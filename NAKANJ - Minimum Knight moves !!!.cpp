#include <bits/stdc++.h>

using namespace std;

pair <int,int> a[8] = {make_pair(1,-2),make_pair(1,2),make_pair(2,-1),make_pair(2,1),
                        make_pair(-1,-2),make_pair(-1,2),make_pair(-2,-1),make_pair(-2,1)};

int mark[8][8];

void solve(pair <int,int> p)
{
    pair <int,int> temp;

    for(int i=0;i<8;i++)
    {
        temp.first = p.first + a[i].first;
        temp.second = p.second + a[i].second;

        if(temp.first >= 0 && temp.first < 8 && temp.second >= 0 && temp.second < 8)
        {
            if(mark[temp.first][temp.second] > mark[p.first][p.second]+1)
            {
                mark[temp.first][temp.second] = mark[p.first][p.second]+1;
                solve(temp);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s1,s2;
        cin >> s1 >> s2;

        pair <int,int> st,ed;

        st.first = s1[0]-'a';
        st.second = s1[1] - '1';

        ed.first = s2[0]-'a';
        ed.second = s2[1] - '1';

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                mark[i][j] = 100000;
        }

        //cout << st.first << " " << st.second << endl;
        //cout << ed.first << " " << ed.second << endl;

        mark[st.first][st.second] = 0;

        solve(st);

        cout << mark[ed.first][ed.second] << endl;
    }
}