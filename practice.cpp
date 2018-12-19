#include <bits/stdc++.h>

using namespace std;

vector <int> v[200010];
int a[200010];
bool visited[200010];
unordered_map <int,int> m;

void dfs(int x)
{
    visited[x] = true;

    for(int i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]])
            dfs(v[x][i]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int temp = 0;

    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
    {
        temp = max(temp,a[i]);

        if(m[a[i]] == 0)
            v[a[i]].push_back(a[i]);

        m[a[i]]++;

        for(int j=i+1;j<n;j++)
        {
            if(__gcd(a[i],a[j]) == 1)
            {
                v[a[i]].push_back(a[j]);
                v[a[j]].push_back(a[i]);
            }
        }
    }

    for(int i=temp;i>=1;i--)
        visited[i] = false;

    int count = 0;

    for(int i=temp;i>=1;i--)
    {
        if(v[i].size() == 0)
            continue;

        if(v[i].size() == 1)
        {
            count += m[i];
            continue;
        }

        if(!visited[i])
            dfs(i), count++;
    }

    cout << count << endl;

    return 0;
}