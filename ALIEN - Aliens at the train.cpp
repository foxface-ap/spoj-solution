#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin >> n >> m;

        int sum = 0;

        for(int i=0;i<n;i++)
            cin >> a[i];

        pair <int,int> ans(0,0);
        int j = 0;

        for(int i=0;i<n;i++)
        {
            sum += a[i];

            while(sum > m)
            {
                sum -= a[j];
                j++;
            }

            if(sum <= m && ans.second <= (i-j+1))
            {
                if(ans.second != (i-j+1) || ans.first > sum)
                {
                    ans.second = i-j+1;
                    ans.first = sum;
                }
            }
        }

        cout << ans.first << " " << ans.second << endl;
    }
}