#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		int x,max=0;

		for(int i=0;i<n;i++)
		{
			cin >> x;
			if(max < x)
				max = x;
		}

		n = max;
		max = 0;

		for(int i=0;i<m;i++)
		{
			cin >> x;
			if(max < x)
				max = x;
		}

		m = max;

		if(n >= m)
			cout << "Godzilla" << endl;
		else
			cout << "MechaGodzilla" << endl;
	}
}