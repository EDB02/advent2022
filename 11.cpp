#include <bits/stdc++.h>

#define int long long

using namespace std;

long long mod = 1;

struct monkey
{
    queue<int> items;
    char op;
    int f1, f2;
    int test;
    int left, right;
    int operation(int item);
};

int monkey::operation(int item)
{
    int a = f1, b = f2;
    if(a == INT32_MIN) a = item;
    if(b == INT32_MIN) b = item;
    switch(op)
    {
        case '+': return (a+b)%mod;
        case '*': return (a*b)%mod;
    }
    return -1;
}

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1, s2;
    char c;
    int a, b;
    vector<monkey*> monkeys;

    while(cin >> s1 >> a >> s2)
    {
        monkey *m = new monkey;
        cin>>s1>>s1;
        while(cin >> s1)
        {
            if(s1[0] == 'O') break;
            m->items.push(stoi(s1));
        }
        cin>>s1>>c>>s1>>c>>s2;
        m->op = c;
        m->f1 = (s1 == "old")?INT32_MIN:stoi(s1);
        m->f2 = (s2 == "old")?INT32_MIN:stoi(s2);
        cin>>s1>>s1>>s1>>a;
        m->test = a;
        mod = lcm(mod, a);
        cin>>s1>>s1>>s1>>s1>>s1>>a;
        cin>>s1>>s1>>s1>>s1>>s1>>b;
        m->right = a;
        m->left = b;
        monkeys.push_back(m);
    }

    vector<int> res(monkeys.size(), 0);
    int turns = 10000;
    for(int t=0;t<turns;t++)
    {
        int i=0;
        for(auto m:monkeys)
        {
            while(m->items.size())
            {
                res[i]++;
                int item = m->items.front();
                m->items.pop();
                item = m->operation(item);
                if(item % m->test) monkeys[m->left]->items.push(item);
                else monkeys[m->right]->items.push(item);
            }
            i++;
        }
    }

    sort(res.begin(), res.end());

    cout<<res[res.size()-1]*res[res.size()-2]<<endl;

    return 0;
}