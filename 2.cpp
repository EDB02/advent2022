#include <bits/stdc++.h>

using namespace std;

int win_to[] = {2, 0, 1};
int to_win[] = {1, 2, 0};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char a, b,c;
    int score = 0, score2 = 0;
    while(cin>>a>>b)
    {
        int p1=a-'A';
        int p2 = b-'X';
        if(win_to[p2] == p1) score+=6;
        else if(p2 == p1) score += 3;
        score+=p2+1;

        if(p2 == 2) score2+=6+to_win[p1]+1;
        else if(p2 == 1) score2 += 3+p1+1;
        else score2+=win_to[p1]+1;
    }
    cout<<score<<endl<<score2<<endl;
    return 0;
}