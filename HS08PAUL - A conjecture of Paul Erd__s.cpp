#include <bits/stdc++.h>
 
using namespace std;
 
bool vis[10000010];
 
int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    for(int i=1e7;i>=0;i--)
        vis[i] = true;
 
    for(int i=2;i*i<=10000000;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=10000000;j+=i)
                vis[j] = false;
        }
    }
 
    vector <int> v;
    set <int> s;
 
    for(int i=1;i*i<=1e7;i++)
    {
        for(int j=1;j*j*j*j<=(1e7-i*i);j++)
        {
            int temp = i*i + j*j*j*j;
 
            if(temp > 1 && vis[temp])
                s.insert(temp);
        }
    }
 
    for(int i:s)
        v.push_back(i);
 
    int t;
    cin >> t;
 
    while(t--)
    {
        int n;
        cin >> n;
 
        cout << upper_bound(v.begin(),v.end(),n) - v.begin() << endl;
    }
 
    return 0;
}