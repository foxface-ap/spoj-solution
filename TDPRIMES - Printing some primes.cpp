#include <bits/stdc++.h>

using namespace std;

bool vis[100000020];

int32_t main()
{
    // um.reserve(1<<15);
    // um.max_load_factor(0.25);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1e8;i>=0;i--)
        vis[i] = true;

    for(int i=2;i*i<=100000000;i++)
    {
        if(vis[i])
        {
            for(int j=i*i;j<=100000000;j+=i)
                vis[j] = false;
        }
    }

    int c = 0;

    for(int i=2;i<=100000000;i++)
    {
        if(vis[i])
        {
            c++;
            
            if(c%100 == 1)
                cout << i << endl;
        }
    }

    return 0;
}