#include <bits/stdc++.h>

using namespace std;

bool vis[100000010];
vector <int> v[20010];

int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1e8;i>=0;i--)
        vis[i] = true;

    vis[0] = vis[1] = false;

    for(int i=2;i*i<=1e8;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=1e8;j+=i)
                vis[j] = false;
        }
    }

    int cnt = 1;
    int cnt_ = 1;

    for(int i=2;i<=1e8;i++)
    {
        if(vis[i])
        {
            v[cnt].push_back(i);

            if(cnt == cnt_)
                cnt++, cnt_ = 0;
            
            cnt_++;
        }
    }

    if(v[cnt].size() == 0)
        cnt--;

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(vis[n])
        {
            int l = 1;
            int h = cnt;
            int ans = 0;

            while(l <= h)
            {
                int mid = (l+h)/2;

                if(v[mid][0] > n)
                    h = mid - 1;
                else
                {
                    l = mid + 1;
                    ans = mid;
                }
            }

            cout << ans << " " << upper_bound(v[ans].begin(),v[ans].end(),n) - v[ans].begin() << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}