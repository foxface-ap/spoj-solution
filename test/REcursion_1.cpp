#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,x;
		cin >> n >> x;

		int y,sum=0;

		bool flag = false;

		for(int i=0;i<n;i++)
		{
			cin >> y;

			sum += y;
		}

		if(sum%x != 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}

	return 0;
}