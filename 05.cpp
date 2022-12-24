#include <bits/stdc++.h>

using namespace std;

void reverse_stack(vector<stack<char> > &v1, vector<stack<char> > &v2)
{
    for(int i=0;i<v1.size();i++)
    {
        while(v1[i].size())
        {
            v2[i].push(v1[i].top());
            v1[i].pop();
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    vector<stack<char> > v;
    bool end = 0;
    while(!end)
    {
        getline(cin, line, '\n');
        for(int i=0, j=0;i<line.size();i+=4,j++)
        {
            if(line[i] == ' ' && line[i+1] == '1')
            {
                end = 1;
                break;
            }
            if(v.size() <= j) v.push_back(stack<char>());
            if(line[i] == '[')
            {
                v[j].push(line[i+1]);
            }
        }
    }

    vector<stack<char> > s1(v.size()), s2(v.size());
    reverse_stack(v, s1);
    s2 = s1;
    int a, b, c;
    vector<int> tmp;

    while(cin>>line>>a>>line>>b>>line>>c)
    {
        tmp.clear();
        for(int i=0;i<a;i++)
        {
            s1[c-1].push(s1[b-1].top());
            s1[b-1].pop();
            tmp.push_back(s2[b-1].top());
            s2[b-1].pop();
        }
        for(int j=tmp.size()-1;j>=0;j--) s2[c-1].push(tmp[j]);
    }

    for(auto i:s1)
        cout<<i.top();
    cout<<endl;
    for(auto i:s2)
        cout<<i.top();

    cout<<endl;

    return 0;
}