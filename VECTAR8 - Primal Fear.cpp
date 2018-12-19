#include <bits/stdc++.h>

using namespace std;

bool vis[1000010];

bool solve(int x)
{
    int temp = 0;
    bool flag = false;
    int cnt = 1;

    while(x)
    {
        if(x%10 == 0)
            return false;

        temp += (x%10)*cnt;

        if(!vis[temp])
            return false;

        cnt *= 10;
        x /= 10;
    }

    return true;
}

int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1e6;i>=0;i--)
        vis[i] = true;

    vis[0] = vis[1] = false;

    for(int i=2;i*i<=1000000;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
                vis[j] = false;
        }
    }

    vector <int> v;

    for(int i=2;i<=1e6;i++)
    {
        if(vis[i] && solve(i))
            v.push_back(i);
    }

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