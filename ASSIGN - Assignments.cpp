#include <bits/stdc++.h>

#define int long long
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

map <pair<int,vector <int> >,int> m;
int c[22][22];
int n;

int solve(int x, vector <int> y)
{
    if(x == n)
        return 1;

    if(m[{x,y}] != 0)
        return m[{x,y}];

    int ans = 0;
    vector <int> v(20,0);

    for(int i=0;i<n;i++)
    {
        v = y;

        if(c[x][i] == 0 || y[i] == 1)
            continue;
        else
        {
            v[i] = 1;
            ans += solve(x+1,v);
        }
    }

    return m[{x,y}] = ans;
}

int32_t main()
{
    fastIO;

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin >> c[i][j];
        }

        m.clear();
        vector <int> v(20,0);

        cout << solve(0,v) << endl;
    }
}