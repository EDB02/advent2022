#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a1, b1, a2, b2;
    char c;
    int res1 = 0, res2 = 0;
    while(cin>>a1>>c>>b1>>c>>a2>>c>>b2)
    {
        res1 += (a1 >= a2 &&b1 <= b2 || a2 >= a1 && b2 <= b1);
        res2 += (a1 >= a2 && a1 <= b2 || a2 >= a1 && a2 <= b1);
    }

    cout<<res1<<endl<<res2<<endl;

    return 0;
}