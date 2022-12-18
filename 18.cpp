#include <bits/stdc++.h>

using namespace std;

#define msize 50

bool matrix[msize][msize][msize];

int xmoves[] = {1, 0, 0, -1, 0, 0};
int ymoves[] = {0, 1, 0, 0, -1, 0};
int zmoves[] = {0, 0, 1, 0, 0, -1};

void parse(string s, int &a, int &b, int &c)
{
    int i = s.find(",");
    a = stoi(s.substr(0, i));
    s = s.substr(i+1);
    i = s.find(",");
    b = stoi(s.substr(0, i));
    s = s.substr(i+1);
    i = s.find(",");
    c = stoi(s.substr(0, i));
}

bool visited[msize][msize][msize];

int bfs(int x, int y, int z)
{
    queue<array<int, 3> > q;
    q.push({x,y,z});
    int ret = 0;
    while(q.size())
    {
        int c_x = q.front()[0];
        int c_y = q.front()[1];
        int c_z = q.front()[2];
        q.pop();
        if(matrix[c_x][c_y][c_z])
        {
            ret++;
            continue;
        }
        if(visited[c_x][c_y][c_z]) continue;
        visited[c_x][c_y][c_z] = 1;
        for(int i=0;i<6;i++)
        {
            int nx = c_x+i[xmoves];
            int ny = c_y+ymoves[i];
            int nz = c_z+zmoves[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= msize || ny >= msize || nz >= msize) continue;
            q.push({nx, ny, nz});
        }
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, z;
    int res1 = 0;
    string l;

    while(getline(cin, l))
    {
        parse(l, x, y, z);
        x++, y++, z++;
        matrix[x][y][z] = 1;
        res1 += 6;
        for(int i=0;i<6;i++)
        {
            int nx = x+xmoves[i];
            int ny = y+ymoves[i];
            int nz = z+zmoves[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= msize || ny >= msize || nz >= msize) continue;
            if(matrix[nx][ny][nz]) res1 -= 2;
        }
    }

    cout<<res1<<endl;
    cout<<bfs(msize-1, msize-1, msize-1)<< endl;

}