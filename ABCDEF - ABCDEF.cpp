#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a[110];
vector <ll> v,s,temp;

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp.push_back(a[i]*a[j]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<temp.size();j++)
            v.push_back(a[i]+temp[j]);
    }

    temp.clear();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            temp.push_back(a[i]+a[j]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<temp.size();j++)
        {
            if(a[i] != 0)
                s.push_back(a[i]*temp[j]);
        }
    }

    sort(s.begin(),s.end());

    int count = 0;

    for(int i=0;i<v.size();i++)
    {
        if(binary_search(s.begin(),s.end(),v[i]))
            count += upper_bound(s.begin(),s.end(),v[i]) - lower_bound(s.begin(),s.end(),v[i]);
    }

    cout << count << endl;
}