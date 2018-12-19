#include <bits/stdc++.h>

#define int long long
#define mod 1000000007
#define p pair<int,int>
#define MAX 1000010

using namespace std;

int spf[500010];

int modular_pow(int base, int exponent, int modulus) 
{ 
    int result = 1; 
  
    while (exponent > 0) 
    { 
        if (exponent & 1) 
            result = (result * base) % modulus; 

        exponent = exponent >> 1; 
  
        base = (base * base) % modulus; 
    } 

    return result; 
} 

int PollardRho(int n) 
{ 
    srand (time(NULL)); 

    if (n==1) 
        return n; 

    if (n % 2 == 0) 
        return 2;

    int x = (rand()%(n-2))+2; 
    int y = x; 
    int c = (rand()%(n-1))+1; 
    int d = 1;   

    while (d==1) 
    {
        x = (modular_pow(x, 2, n) + c + n)%n; 
        y = (modular_pow(y, 2, n) + c + n)%n; 
        y = (modular_pow(y, 2, n) + c + n)%n; 
        d = __gcd(abs(x-y), n); 

        if (d==n) 
            return PollardRho(n); 
    } 
  
    return d; 
}

bool miillerTest(int d, int n) 
{ 
    int a = 2 + rand() % (n - 4); 

    int x = modular_pow(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 

    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 

    return false; 
} 
bool isPrime(int n, int k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 

    int d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 

    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<500010;i++)
        spf[i] = i;

    for(int i=2;i*i<=500000;i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i;j<=500000;j+=i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        int to = n;

        set <int> v;

        for(int i=1;i<=5e5;i++)
        {
            if(n%i == 0)
            {
                v.insert(i);
                v.insert(n/i);
            }
        }     

        if(n == 1)
            ;
        else if(isPrime(n,100))
            v.insert(n);
        else
        {
            int temp = PollardRho(n);
            v.insert(temp);
            v.insert(n/temp);
        }

        int ans = 0;

        for(int i:v)
        {
            if(i < to)
                ans += i;
        }

        cout << ans << endl;
    }

    return 0;
}