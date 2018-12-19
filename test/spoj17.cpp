#include <bits/stdc++.h>

using namespace std;

vector <int> v;

bool a[100010];

void prime()
{
	for(int i=2;i<100000;i++)
	{
		if(a[i])
		{
			v.push_back(i);

			for(int j=2*i;j<100000;j+=i)
				a[j] = false;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	memset(a,true,100010*sizeof(a[0]));

	prime();

	while(t--)
	{
		int a,b;
		cin >> a >> b;

		vector <int> m,s;

		for(int i=a;i<=b;i++)
			m.push_back(i);

		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<m.size();j++)
			{
				if(m[j]%v[i] != 0)
					s.push_back(m[j]);
			}

			m.clear();
			m = s;
			s.clear();
		}

		for(int i=0;i<m.size();i++)
			cout << m[i] << endl;
	}
}