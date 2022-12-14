#include <bits/stdc++.h>

using namespace std;

#define mat_size 2000

int mat[mat_size][mat_size];

bool pour(int x, int y)
{
    if(mat[x][y]) return 0;
    if(x < 0 || x >= mat_size || y < 0 || y >= mat_size) return 0;
    if(!mat[x][y+1]) return pour(x, y+1);
    if(!mat[x-1][y+1]) return pour(x-1, y+1);
    if(!mat[x+1][y+1]) return pour(x+1, y+1);
    mat[x][y] = 2;
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    char c;
    int x, y;
    vector<vector<pair<int,int> > > paths;
    int i = 0;
    int maxy = 0;
    while(cin >> x >> c >> y)
    {
        maxy = max(maxy, y);
        if(paths.size() == i) paths.push_back(vector<pair<int, int>>());
        paths[i].push_back({x,y});
        c = getchar();
        if(c == '\n')
        {
            i++;
            continue;
        }
        cin>>c>>c;
    }
    for(auto i:paths)
    {
        for(int j=1;j<i.size();j++)
        {
            if(i[j].first == i[j-1].first)
            {
                int a = min(i[j].second, i[j-1].second);
                int b = max(i[j].second, i[j-1].second);
                for(int k=a;k<=b;k++) mat[i[j].first][k] = 1;
            }
            else
            {
                int a = min(i[j].first, i[j-1].first);
                int b = max(i[j].first, i[j-1].first);
                for(int k=a;k<=b;k++) mat[k][i[j].second] = 1;
            }
        }
    }
    //res2

    for(int i=0;i<mat_size;i++) mat[i][maxy+2] = 1;

    int res = 0;

    while(pour(500, 0)) 
        res++;

    cout<<res<<endl;

    return 0;
}