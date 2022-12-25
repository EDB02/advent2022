#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<char, ll> values = {{'0', 0}, {'1', 1}, {'2', 2}, {'=', -2}, {'-', -1}};

ll convert(string n)
{
    ll ret = 0;
    for(int i=n.size()-1;i>=0;i--)
        ret += values[n[i]] * pow(5, n.size()-i-1);
    return ret;
}

string convert(ll n)
{
    string tmp = "";
    while(n)
    {
        tmp = (char)('0'+n%5) + tmp;
        n /= 5;
    }
    tmp = "0000" + tmp;
    for(int i=tmp.size()-1;i>0;i--)
    {
        if(tmp[i] == '3')
        {
            tmp[i] = '=';
            tmp[i-1]++;
        }
        else if(tmp[i] == '4')
        {
            tmp[i] = '-';
            tmp[i-1]++;
        }
        else if(tmp[i] > '4')
        {
            tmp[i] = '0' + (tmp[i]-'0')%5;
            tmp[i-1] = '0' + (tmp[i]-'0')/5;
        }
    }
    return tmp.substr(tmp.find_first_not_of('0'));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    ll res1 = 0;
    while(getline(cin, s))
        res1 += convert(s);

    cout<<convert(res1)<<endl;

    return 0;
}