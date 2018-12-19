#include <bits/stdc++.h>
#define int long long
using namespace std;
 
bool vis[100010];
vector <int> v;
 
int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    for(int i=1e5;i>=0;i--)
        vis[i] = true;
 
    vis[0] = vis[1] = false;
 
    for(int i=2;i*i<=1e5;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=1e5;j+=i)
                vis[j] = false;
        }
    }
 
    for(int i=2;i<=1e5;i++)
    {
        if(vis[i])
            v.push_back(i*i);
    }
 
    int t;
    cin >> t;
 
    while(t--)
    {
        int n,k;
        cin >> n >> k;
 
        int t1 = upper_bound(v.begin(),v.end(),n) - v.begin();
        int t2 = upper_bound(v.begin(),v.end(),k) - v.begin();
 
        cout << t1 << " " << max(0LL,t1-t2) << endl;
    }
 
    return 0;
} 