#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s = "";
    char c;
    int mas = 0, tmp = 0;
    vector<int> sk;
    while(!cin.eof())
    {
        getline(cin, s);
        if(s.size() <= 0)
        {
            sk.push_back(tmp);
            tmp = 0;
            continue;
        }
        tmp += stoi(s);
        s = "";
    }
    sk.push_back(tmp);
    sort(sk.begin(), sk.end());
    int res = 0;
    for(int i=0;i<3;i++) res += sk[sk.size()-i-1];
    cout<<sk[sk.size()-1]<<endl;
    cout<<res<<endl;
}