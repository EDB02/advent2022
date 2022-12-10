#include <bits/stdc++.h>

using namespace std;

int clock_c = 0;
int res1 = 0;
int x = 1;
vector<vector<char> > screen(6, vector<char>(40, '.'));
int drawing_x = 0, drawing_y = 0;

void new_cycle(int c)
{
    while(c--)
    {
        clock_c++;
        if((clock_c-20) % 40 == 0)
            res1 += clock_c * x;
        
        if(abs(x-drawing_x) <= 1)
            screen[drawing_y][drawing_x] = '#';

        drawing_x++;
        if(drawing_x >= 40)
            drawing_x = 0, drawing_y++;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int tmp;
    while(cin >> s)
    {
        if(s == "addx")
        {
            cin>>tmp;
            new_cycle(2);
            x += tmp;
        }
        else
            new_cycle(1);
    }

    cout<<res1<<endl;

    for(auto i:screen)
    {
        for(auto j:i) cout<<j;
        cout<<endl;
    }

    return 0;
}