#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct item{
    string filename;
    bool isfolder;
    ll size;
    item* parent;
    map<string, item*> children;
} *root, *current;

ll res1 = 0;

vector<ll> sizes;

int dfs(item* i)
{
    ll s = 0;
    for(auto x:i->children)
    {
        if(x.second->isfolder)
            x.second->size = dfs(x.second);
        s += x.second->size;
    }
    if(s < 100000) res1 += s;
    sizes.push_back(s);
    return s;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, s2, command;

    current = root = new item{"/", 1, 0, NULL};

    getline(cin, s);
    cin>>s;

    while(cin>>command)
    {
        if(command == "cd")
        {
            cin>>s;
            if(s == "..") current = current->parent;
            else
            {
                if(current->children[s] == NULL)
                    current = new item{s, 1, 0, current};
                else current = current->children[s];
            }
            cin>>s;
        }
        else
        {
            while(cin>>s)
            {
                if(s[0] == '$') break;
                item *tmp;
                cin>>s2;
                if(s == "dir")
                    tmp = new item{s2, 1, 0, current};
                else
                    tmp = new item{s2, 0, stoi(s), current};
                current->children[tmp->filename] = tmp;
            }
        }
    }

    ll free = 70000000 - dfs(root);
    ll target = 30000000 - free;
    sort(sizes.begin(), sizes.end());
    ll res2 = *upper_bound(sizes.begin(), sizes.end(), target);

    cout<<res1<<endl;
    cout<<res2<<endl;

    return 0;
}