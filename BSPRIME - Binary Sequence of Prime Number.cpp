#include <bits/stdc++.h>
#define int long long
using namespace std;

int vis[1000010];
vector <int> v[20];

int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1e6;i>=0;i--)
        vis[i] = 0;

    for(int i=2;i*i<=1e6;i++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;

            for(int j=i*i;j<=1e6;j+=i)
                vis[j]++;
        }
    }

    for(int i=1;i<=1e6;i++)
        v[vis[i]].push_back(i);
    
    int t;
    cin >> t;

    while(t--)
    {
        int a,b,x;
        cin >> a >> b >> x;

        cout << upper_bound(v[x].begin(),v[x].end(),b) - lower_bound(v[x].begin(),v[x].end(),a) << endl;
    }

    return 0;
}