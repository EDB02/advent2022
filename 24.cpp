#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
int mod = 1;

vector<vector<int> > matrix;
vector<vector<vector<int> > > matrix_t;
vector<array<int, 3> > blz;
int xmoves[] = {-1, 0, 1, 0, 0};
int ymoves[] = {0, 1, 0, -1, 0};

void init(int mod)
{
    for(int i=0;i<mod;i++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                matrix_t[x][y][i] = matrix[x][y];
            }
        }
        for(int j=0;j<blz.size();j++)
        {
            int x = blz[j][1];
            int y = blz[j][2];
            int n_x = x + xmoves[blz[j][0]];
            int n_y = y + ymoves[blz[j][0]];
            if(n_x <= 0) n_x = n-2;
            else if(n_x >= n-1) n_x = 1;
            if(n_y <= 0) n_y = m-2;
            else if(n_y >= m-1) n_y = 1;
            blz[j][1] = n_x;
            blz[j][2] = n_y;
            matrix[x][y]--;
            matrix[n_x][n_y]++;
        }
    }
}

int bfs(int startx, int starty, int endx, int endy, int start_t)
{
    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(mod, 2e9)));
    vector<vector<vector<bool> > > visited(n, vector<vector<bool> >(m, vector<bool>(mod, 0)));
    queue<array<int, 3>> pq;
    dist[startx][starty][start_t % mod] = 0;
    pq.push({-start_t, startx, starty});
    while(pq.size())
    {
        int d = -pq.front()[0];
        int x = pq.front()[1];
        int y = pq.front()[2];
        pq.pop();
        if(visited[x][y][d%mod]) continue;
        if(x == endx && y == endy) break;
        visited[x][y][d%mod] = 1;
        for(int i=0;i<5;i++)
        {
            int n_x = x + xmoves[i];
            int n_y = y + ymoves[i];
            if(n_x >= 0 && n_x < n && n_y >= 0 && n_y < m &&
                matrix_t[n_x][n_y][(d+1)%mod] == 0 &&
                dist[n_x][n_y][(d+1)%mod] > d+1 && 
                !visited[n_x][n_y][(d+1)%mod])
            {
                dist[n_x][n_y][(d+1)%mod] = d+1;
                pq.push({-(d+1), n_x, n_y});
            }
        }
    }
    return *min_element(dist[endx][endy].begin(), dist[endx][endy].end());
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string l;
    int x = 0;
    while(getline(cin, l))
    {
        if(l.size() <= 0) break;
        vector<int> tmp;
        int y = 0;
        for(auto i:l)
        {
            if(i == '#') tmp.push_back(-1);
            else if(i == '.') tmp.push_back(0);
            else
            {
                tmp.push_back(1);
                if(i == '^') blz.push_back({0, x, y});
                else if(i == '>') blz.push_back({1, x, y});
                else if(i == 'v') blz.push_back({2, x, y});
                else blz.push_back({3, x, y});
            }
            y++;
        }
        matrix.push_back(tmp);
        x++;
    }
    n = matrix.size();
    m = matrix[0].size();

    mod = lcm(n-2, m-2);    //every lcm(n-2, m-2) iteration the matrix will be the same as start
    matrix_t.resize(n, vector<vector<int> >(m, vector<int>(mod, 0)));
    init(mod);

    int a = bfs(0, 1, n-1, m-2, 0);
    int b = bfs(n-1, m-2, 0, 1, a);
    int c = bfs(0, 1, n-1, m-2, b);
    
    cout<<a<<endl;
    cout<<c<<endl;
    return 0;
}