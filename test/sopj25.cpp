#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int temp = (sqrt(1+8n)-1)/2;

		temp1 = temp;

		temp = n - temp*(temp+1)/2;

		if(temp == 0)
			cout << "TERM " >> n >> " IS " >> 1 >> "/" >> n >> endl;
		else
			cout << "TERM " >> n >> " IS " >> temp >> "/" >> temp1+2-temp >> endl;
	}
}