#include <bits/stdc++.h>

using namespace std;

int ymoves[] = {1,0,-1,0};
int xmoves[] = {0,1,0,-1};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> mat;
    string s;
    int n, m;
    int start_x, start_y, end_x, end_y;
    while(cin >> s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'S') s[i] = 'a', start_x = i, start_y = mat.size();
            else if(s[i] == 'E') s[i] = 'z', end_x = i, end_y = mat.size();
        }
        mat.push_back(s);
    }
    n = mat.size(), m = mat[0].size();

    queue<pair<int, int> > q;
    vector<vector<bool> > done(n, vector<bool>(m, 0));
    vector<vector<int> > dist(n, vector<int>(m, 2e9));

    dist[end_y][end_x] = 0;
    q.push({end_y, end_x});

    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(done[y][x]) continue;
        done[y][x] = 1;
        for(int i=0;i<4;i++)
        {
            int nx = x + xmoves[i];
            int ny = y + ymoves[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n
                && !done[ny][nx] && dist[ny][nx] > dist[y][x]+1
                && mat[y][x]-mat[ny][nx] <= 1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout<<dist[start_y][start_x]<<endl;

    int res2 = 2e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j] == 'a') 
                res2 = min(res2, dist[i][j]);
    cout<<res2<<endl;

    return 0;
}