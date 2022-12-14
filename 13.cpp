#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v;
    vector<node*> l;
};

int compare(node *n1, node *n2)
{
    if(n1->v >= 0)
    {
        if(n2->v >= 0)
        {
            if(n1->v < n2->v) return 1;
            if(n1->v > n2->v) return -1;
            return 0;
        }
        if(n2->l.size() <= 0) return -1;
        return compare(new node{-1, {n1}}, n2);
    }
    if(n2->v >= 0)
    {
        if(n1->l.size() <= 0) return 1;
        return compare(n1, new node{-1, {n2}});
    }
    int cnt = 0;
    for(int i=0;i<n1->l.size();i++)
    {
        if(n2->l.size() <= i) return -1;
        int sk = compare(n1->l[i], n2->l[i]);
        cnt++;
        if(sk != 0) return sk;
    }
    if(n1->l.size() == cnt && n2->l.size() == cnt) return 0;
    return 1;
}

int convert(string s, int i, node *n)
{
    if(i >= s.size()) return i;
    if(s[i] == '[')
    {
        n->l.push_back(new node{-1});
        return convert(s, convert(s, i+1, n->l[n->l.size()-1]), n);    
    }
    if(s[i] == ']') return i+1;
    if(s[i] == ',') return convert(s, i+1, n);
    int ind = min(s.find("]", i), s.find(",", i));
    int c = stoi(s.substr(i, ind-i));
    n->l.push_back(new node{c});
    if(s[ind] == ']') return ind+1;
    return convert(s, ind+1, n);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1, s2;
    int i1 = 0, i2 = 0;
    int res1 = 0;
    int i = 1;

    int d1 = 1, d2 = 2;
    node *divider1 = new node{-1, {new node{-1, {new node{2}}}}};
    node *divider2 = new node{-1, {new node{-1, {new node{6}}}}};
    while(cin>>s1>>s2)
    {
        node *n1 = new node{-1}, *n2 = new node{-1};
        convert(s1, 1, n1);
        convert(s2, 1, n2);
        if(compare(n1, divider1) != -1) d1++;
        if(compare(n2, divider1) != -1) d1++;
        if(compare(n1, divider2) != -1) d2++;
        if(compare(n2, divider2) != -1) d2++;
        if(compare(n1, n2) != -1) res1 += i, cout<<i<<" ";
        i++;
    }
    cout<<endl;

    cout<<res1<<endl;
    cout<<d1*d2<<endl;

    return 0;
}