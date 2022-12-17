#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int> > g;
map<string, int> ids;
vector<int> flows;
int n = 0;
int no_zero = 0;
vector<vector<int> > dist;
vector<bool> done;

void bfs()
{
    for(int i=0;i<n;i++)
    {
        fill(done.begin(), done.end(), 0);
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            if(done[cur]) continue;
            done[cur] = 1;

            for(int x:g[cur])
            {
                if(!done[x] && dist[i][x] > dist[i][cur]+1)
                {
                    dist[i][x] = dist[i][cur]+1;
                    q.push(x);
                }
            }
        }
    }
}

map<ll, array<array<int, 31>, 100> > mem;

int dp(int i, int m, ll opened)
{
    if(m <= 0) return 0;

    if(mem[opened][i][m]) return mem[opened][i][m];
    int ret = 0;
    for(int j=0;j<n;j++)
    {
        if(flows[j] && !((opened>>j) & 1) && m > dist[i][j]+1) 
            ret = max(ret, dp(j, m-dist[i][j]-1, (opened | (1LL<<j))));     //il porco di dio (1<<50) = 0 dio boia
    }
    return mem[opened][i][m] = (ret + (flows[i]*m));
}

vector<vector<vector<vector<map<ll, int> > > > > mem2(60, vector<vector<vector<map<ll, int> > > >(60, vector<vector<map<ll, int> > >(27, vector<map<ll, int> >(27))));

int dp2(int i, int e, int m, int me, ll opened)
{
    if(m < 0 || me < 0) return -2e9;
    if(m == 0 && me == 0) return 0;
    if(__builtin_popcount(opened) >= no_zero) return 0; 
    if(mem2[i][e][m][me][opened]) return mem2[i][e][m][me][opened];
    int ret = 0;
    for(int j=0;j<n;j++)
    {
        if(flows[j] == 0 || ((opened>>j) & 1)) continue;
        if(m > dist[i][j]+1) 
            ret = max(ret, 
            dp2(j, e, m-dist[i][j]-1, me, (opened | (1LL<<j))) + (flows[j]*(m-dist[i][j]-1)));
        if(me > dist[e][j]+1)
            ret = max(ret, 
            dp2(i, j, m, me-dist[e][j]-1, (opened | (1LL<<j))) + (flows[j]*(me-dist[e][j]-1)));
    }
    return mem2[i][e][m][me][opened] = ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    string t, tmp;
    int f1 = 0;
    vector<vector<string> > v;

    while(cin>>t>>s>>t>>t>>t)
    {
        vector<string> tmp_v;
        f1 = stoi(t.substr(5));
        cin>>t>>t>>t>>t;
        flows.push_back(f1);
        tmp_v.push_back(s);
        no_zero += f1 != 0;
        while(1)
        {
            cin>>tmp;
            tmp_v.push_back(tmp.substr(0,2));
            if(tmp[tmp.size()-1] != ',') break;
        }
        v.push_back(tmp_v);
    }

    n = v.size();
    for(int i=0;i<v.size();i++)
    {
        ids[v[i][0]] = i;
    }
    g.resize(n);
    done.resize(n);
    dist.resize(n, vector<int>(n, 2e9));

    for(int i=0;i<v.size();i++)
    {
        for(int j=1;j<v[i].size();j++)
        {
            g[ids[v[i][0]]].push_back(ids[v[i][j]]);
        }
    }

    bfs();
    cout<<dp(ids["AA"], 30, 0)<<endl;
    cout<<dp2(ids["AA"], ids["AA"], 26, 26, 0)<<endl;       //ci mette tipo 5 minuti
    return 0;
}