#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;

	while(a != -1 && b != -1)
	{
		if(a < b)
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}
		
		b++;
		int temp = a/b;

		if(a%b != 0)
			temp++;

		cout << temp << endl;

		cin >> a >> b;
	}
}