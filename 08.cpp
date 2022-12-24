#include <bits/stdc++.h>

using namespace std;

int x_moves[] = {1,0,-1,0};
int y_moves[] = {0,1,0,-1};
int n;
vector<string> mat;
vector<vector<bool> > visible;

void f1(int x, int y, int d_x, int d_y)
{
    char mas = mat[x][y];
    while(1)
    {
        int n_x = x+d_x;
        int n_y = y+d_y;
        if(!(n_x < n-1 && n_x > 0 && n_y > 0 && n_y < n-1)) break;
        if(mas < mat[n_x][n_y])
            visible[n_x][n_y] = 1;
        x = n_x;
        y = n_y;
        mas = max(mas, mat[x][y]);
    }
}

int f2(int x, int y)
{
    int a=0, b=0, c=0, d=0;
    for(int i=x-1;i>=0;i--)
    {
        a++;
        if(mat[i][y] >= mat[x][y]) break;
    }
    for(int i=x+1;i<n;i++)
    {
        b++;
        if(mat[i][y] >= mat[x][y]) break;
    }
    for(int i=y-1;i>=0;i--)
    {
        c++;
        if(mat[x][i] >= mat[x][y]) break;
    }
    for(int i=y+1;i<n;i++)
    {
        d++;
        if(mat[x][i] >= mat[x][y]) break;
    }
    return a*b*c*d;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    while(cin >> line) mat.push_back(line);
    n = mat.size();

    visible.resize(n, vector<bool>(n, 0));

    for(int i=1;i<n-1;i++)
    {
        f1(0, i, 1, 0);
        f1(n-1, i, -1, 0);
        f1(i, 0, 0, 1);
        f1(i, n-1, 0, -1);
    }

    int res1 = 4*(n-1);
    for(auto i:visible)
        for(auto j:i)
            res1 += j;

    int res2 = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            res2 = max(res2, f2(i, j));

    cout<<res1<<endl;
    cout<<res2<<endl;

    return 0;
}