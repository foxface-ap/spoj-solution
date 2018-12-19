#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		ll int a,b,s;
		cin >> a >> b >> s;

		ll int n = 2*s/(a+b);

		b -= a;

		ll int temp = b/(n-5);

		a = a-2*temp;

		cout << n << endl;

		for(int i=0;i<n;i++)
			cout << a+temp*i << " ";
		cout << endl;
	}
}