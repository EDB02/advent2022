#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targety = 10;//2000000;

    string s;
    int sx, sy, bx, by;
    vector<pair<int, int> > intervals;
    ll res1 = 0;
    map<int, bool> removed;
    vector<int> v_sx, v_sy, v_bx, v_by;
    int start = 2e9;

    while(scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &sx, &sy, &bx, &by) >= 0)
    {
        start = min(start, sy);
        v_sx.push_back(sx);
        v_sy.push_back(sy);
        v_bx.push_back(bx);
        v_by.push_back(by);
        int s = abs(sx-bx)+abs(sy-by);
        int d = abs(targety - sy);
        int t = (s-d)*2+1;
        if(t > 0)
        {
            if(by == targety && !removed[bx])
            {
                res1--;
                removed[bx] = 1;
            }
            intervals.push_back({sx-t/2-1, sx+t/2});
        }
    }
    sort(intervals.begin(), intervals.end());
    int last = intervals[0].first;
    for(auto i:intervals)
    {
        if(i.second <= last) continue;
        res1 += (ll)(i.second - max(last, i.first));
        last = max(i.second, last);
    }

    cout<<res1<<endl;

    //2
    ll res2 = 0;
    for(int target = max(0, start); target <= 4000000; target++)
    {
        intervals.clear();
        for(int i=0;i<v_sx.size();i++)
        {
            int s = abs(v_sx[i]-v_bx[i])+abs(v_sy[i]-v_by[i]);
            int d = abs(target - v_sy[i]);
            int t = (s-d)*2+1;
            if(t > 0)
            {
                intervals.push_back({v_sx[i]-t/2-1, v_sx[i]+t/2});
            }
        }
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());
        int last = intervals[0].first;
        for(auto i:intervals)
        {
            if(i.first > last && i.first >= 0 && i.first <= 4000000)
            {
                res2 = (i.first) * (ll)4000000;
                break;
            }
            last = max(last, i.second);
        }
        if(res2)
        {
            res2 += target;
            break;
        }
    }

    cout<<res2<<endl;

    return 0;
}