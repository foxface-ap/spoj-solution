#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    if(n > 31)
        cout << m << endl;
    else
    {
        n = pow(2,n);
        cout << m%n << endl;
    }
}