#include <bits/stdc++.h>

using namespace std;

int check(string s, int n)
{
    bool ck;
    for(int i=0;i<s.size()-n;i++)
    {
        ck = 1;
        for(int j=0;j<n && ck;j++)
        {
            for(int k=j+1;k<n && ck;k++)
            {
                ck = s[i+j] != s[i+k];
            }
        }
        if(ck)
        {
            return i+n;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin>>s;   

    cout<<check(s, 4)<<endl;
    cout<<check(s, 14)<<endl;

    return 0;
}