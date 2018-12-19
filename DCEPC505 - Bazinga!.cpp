#include <bits/stdc++.h>
#define int long long
using namespace std;

bool vis[10000010];
vector <int> v,v1;

int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1e7;i>=0;i--)
        vis[i] = true;

    vis[0] = vis[1] = false;

    for(int i=2;i*i<=1e7;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=1e7;j+=i)
                vis[j] = false;
        }
    }

    for(int i=2;i<=1e7;i++)
    {
        if(vis[i])
            v.push_back(i);
    }

    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]*v[j] > 20000000)
                break;
            else
                v1.push_back(v[i]*v[j]);
        }
    }

    sort(v1.begin(),v1.end());
    
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << v1[n-1] << endl;
    }

    return 0;
}