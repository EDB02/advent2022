#include <bits/stdc++.h>

using namespace std;

set<pair<int, int> > visited1, visited2;

bool is_adj(int x1, int y1, int x2, int y2)
{
    return max(abs(x1-x2), abs(y1-y2)) <= 1;
}

int m_x[] = {1, 0, -1, 0};
int m_y[] = {0, 1, 0, -1};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char d;
    int s, m=0;

    int t_cnt = 10;

    vector<int> xs(t_cnt, 0);
    vector<int> ys(t_cnt, 0);

    while(cin >> d >> s)
    {
        switch(d)
        {
            case 'U': m=2; break;
            case 'D': m=0; break;
            case 'R': m=1; break;
            case 'L': m=3; break;
        }
        for(int j=0;j<s;j++)
        {
            xs[0] += m_x[m];
            ys[0] += m_y[m];
            for(int i=1;i<t_cnt;i++)
            {
                if(!is_adj(xs[i], ys[i], xs[i-1], ys[i-1]))
                {
                    if(ys[i] == ys[i-1])
                    {
                        if(xs[i] > xs[i-1]) xs[i]--;
                        else xs[i]++;
                    }
                    else if(xs[i] == xs[i-1])
                    {
                        if(ys[i] > ys[i-1]) ys[i]--;
                        else ys[i]++;
                    }
                    else
                    {
                        if(xs[i] > xs[i-1])
                        {
                            if(ys[i] > ys[i-1]) ys[i]--;
                            else ys[i]++;
                            xs[i]--;
                        }
                        else
                        {
                            if(ys[i] > ys[i-1]) ys[i]--;
                            else ys[i]++;
                            xs[i]++;
                        }
                    }
                }
            }
            visited1.insert({xs[1], ys[1]});
            visited2.insert({xs[9], ys[9]});
        }
    }
    visited1.insert({0,0});
    visited2.insert({0,0});
    cout<<visited1.size()<<endl;
    cout<<visited2.size()<<endl;

    //print matrix
    for(int i=-30;i<30;i++)
    {
        for(int j=-30;j<30;j++)
        {
            if(i == 0 && j == 0) cout<<"S";
            else if(visited2.count({i,j})) cout<<'#';
            else cout<<'.';
        }
        cout<<endl;
    }

    return 0;
}