#include <bits/stdc++.h>

using namespace std;

char find_item(string s)
{
    set<char> st;
    for(int i=0;i<s.size()/2;i++)
        st.insert(s[i]);
        
    for(int i=s.size()/2;i<s.size();i++)
        if(st.count(s[i])) return s[i];
    return 'a';
}

char find_badge(vector<string> g)
{
    set<char> s1, s2;
    for(int j=0;j<g[0].size();j++) s1.insert(g[0][j]);
    for(int j=0;j<g[1].size();j++) s2.insert(g[1][j]);
    for(int i=0;i<g[2].size();i++)
    {
        char c = g[2][i];
        if(s1.count(c) && s2.count(c)) return c;
    }
    return 'a';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    char c;
    int sum = 0, sum2 = 0;
    vector<string> groups;

    while(cin>>s)
    {
        c = find_item(s);
        sum += ((c <= 'z' && c >= 'a')?c-'a'+1:c-'A'+27);
        
        groups.push_back(s);
        if(groups.size() >= 3)
        {
            c = find_badge(groups);
            groups.clear();
            sum2 +=((c <= 'z' && c >= 'a')?c-'a'+1:c-'A'+27);
        }
    }

    cout<<sum<<endl;
    cout<<sum2<<endl;

    return 0;
}