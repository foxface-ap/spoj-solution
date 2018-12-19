#include <bits/stdc++.h>

#define int long long
#define mod 1000000007
#define p pair<int,int>
#define MAX 1000010

int spf[500010];

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<500010;i++)
        spf[i] = i;

    for(int i=2;i*i<=500000;i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i;j<=500000;j+=i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int t1 = n;

        map <int,int> m;

        while(spf[n] != 1)
        {
            m[spf[n]]++;
            n /= spf[n];
        }

        int ans = 1;

        for(auto i:m)
        {
            int temp = pow(i.first,i.second+1) - 1;
            temp /= (i.first-1);
            ans *= temp;
        }

        cout << ans-t1 << endl;
    }

    return 0;
}