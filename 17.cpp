#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int> > rocks = {
    {
        15
    },
    {
        2,
        7,
        2
    },
    {
        1,
        1,
        7
    },
    {
        1,
        1,
        1,
        1
    },
    {
        3,
        3
    }
};
int rock_i = 0, wind_i = 0;
int nw, nr = rocks.size();
string wind;
vector<int > matrix(100000, 0);
int top = -1;

int get_wind()
{
    return (wind[(wind_i++)%nw] == '>')*2 - 1;  //1 right, -1 left
}

bool check_collision(vector<int> rock, int x, int y, int maxx)
{
    if(x < 0 || maxx >= 7) return 0;
    if(y < 0) return 0;

    for(int i=0;i<rock.size();i++)
    {
        if((matrix[y+(rock.size()-i-1)]>>(6-maxx)) & rock[i]) return 0;
    }
    return 1;

}

void debug()
{
    for(int i=top;i>=0;i--)
    {
        for(int j=6;j>=0;j--)
            cout<<(((matrix[i]>>j)&1)?'#':'.');
        cout<<endl;
    }
    cout<<endl;
}

void place()
{
    auto rock = rocks[(rock_i++)%nr];
    int x = 2, y = top+4;
    int mas = *max_element(rock.begin(), rock.end());
    int sk = log2(mas);
    int w;
    while(1)
    {
        w = get_wind();
        if(check_collision(rock, x+w, y, sk+x+w)) x+=w;
        if(check_collision(rock, x, y-1, sk+x)) y--;
        else break;
    }
    //save on matrix
    for(int i=0;i<rock.size();i++)
        matrix[y+(rock.size()-i-1)] |= (rock[i]<<(6-sk-x));
    top = max(top, (int)(y+rock.size()-1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    getline(cin, wind);
    nw = wind.size();
    for(int i=0;i<2022;i++)
        place();
    cout<<top+1<<endl;  //res1

    //res2
    fill(matrix.begin(), matrix.end(), 0);
    rock_i = 0;
    wind_i = 0;
    top = -1;
    map<array<int, 3>, pair<int, int> > check;
    ll cnt = 0;
    while(1)
    {
        place();
        if(check[{matrix[top], wind_i%nw, rock_i%nr}].first)
            break;
        check[{matrix[top], wind_i%nw, rock_i%nr}] = {top, cnt};
        cnt++;
    }
    auto tmp = check[{matrix[top], wind_i%nw, rock_i%nr}];
    ll res2 = ((1000000000000LL-tmp.second) / (cnt-tmp.second))*(top-tmp.first) + tmp.first;
    int tmp2 = top;
    int tmp3 = (1000000000000LL-tmp.second) % (cnt-tmp.second);
    for(int i=0;i<tmp3;i++)
    {
        place();
    }
    res2 += (ll)(top-tmp2);

    cout<<res2<<endl;

    return 0;
    
}