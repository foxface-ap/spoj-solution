#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> v;
int p[100010];
 
int main()
{
    memset(p,0,100010*sizeof(p[0]));
 
    for(int i=2;i*i<100010;i++)
    {
        if(p[i] == 0)
        {
            for(int j=2*i;j<100010;j+=i)
                p[j]++;
        }
    }
 
    for(int i=2;i<100010;i++)
    {
        if(i == 1902)
            cout << p[i] << endl;

        if(p[i] > 2)
            v.push_back(i);
    }
 
    int t;
    cin >> t;
 
    while(t--)
    {
        int n;
        cin >> n;
 
        cout << v[n-1] << endl;
    }
} 