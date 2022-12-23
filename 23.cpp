#include <bits/stdc++.h>

#define m_size 1000
using namespace std;

vector<vector<bool> > matrix(m_size, vector<bool>(m_size, 0));
vector<array<int, 2> > elves;
queue<array<int, 3> > proposals;

int checkx[][3] = {{-1,-1,-1}, {1,1, 1}, {1,0,-1}, {1,0,-1}};
int checky[][3] = {{ 1, 0,-1}, {1,0,-1}, {-1,-1,-1}, {1,1,1}};

bool has_neighbour(int x, int y)
{
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
            if((i != 0 || j!= 0) && matrix[x+i][y+j]) return 1;
    }
    return 0;
}

bool check_direction(int x, int y, int r)
{
    bool ret = 0;
    for(int i=0;i<3;i++)
        ret |= matrix[x+checkx[r][i]][y+checky[r][i]];
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int r = m_size/3;
    while(getline(cin, s))
    {
        for(int i=0;i<s.size();i++)
        {
            matrix[r][i+m_size/3] = (s[i] == '#');
            if(s[i] == '#') elves.push_back({r, i+m_size/3});
        }
        r++;
    }

    int res2 = 0;

    for(int round = 0;/*round < 10*/1;round++)
    {
        int ind = 0;
        map<pair<int, int>, int> check_double;
        for(auto i:elves)
        {
            if(has_neighbour(i[0], i[1]))
            {
                for(int j=0;j<4;j++)
                {
                    int r = (round+j)%4;
                    if(!check_direction(i[0], i[1], r))
                    {
                        check_double[{i[0]+checkx[r][1], i[1]+checky[r][1]}]++;
                        proposals.push({ind, i[0]+checkx[r][1], i[1]+checky[r][1]});
                        break;
                    }
                }
            }
            ind++;
        }
        bool ck = 1;
        while(proposals.size())
        {
            auto cur = proposals.front();
            proposals.pop();
            if(check_double[{cur[1], cur[2]}] > 1) continue;
            ck = 0;
            matrix[elves[cur[0]][0]][elves[cur[0]][1]] = 0;
            matrix[cur[1]][cur[2]] = 1;
            elves[cur[0]] = {cur[1], cur[2]};
        }
        if(ck)
        {
            res2 = round+1;
            break;
        }
    }

    cout<<res2<<endl;

    return 0;

    int res1 = -(elves.size());

    int minx = (*min_element(elves.begin(), elves.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; }))[0];
    int maxx = (*max_element(elves.begin(), elves.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; }))[0];
    int miny = (*min_element(elves.begin(), elves.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; }))[1];
    int maxy = (*max_element(elves.begin(), elves.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; }))[1];

    res1 += (maxx-minx+1)*(maxy-miny+1);

    cout<<res1<<endl;

    return 0;
}