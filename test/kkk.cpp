#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() 
{
    clock_t t;
    t = clock();

    vector<ll int> primes;
    primes.push_back(2);

    for (ll int i = 3; i <= 46341; i+=2) 
    {
        bool isprime = true;
        ll int cap = sqrt(i) + 1;

        vector<ll int>::iterator p;

        for (p = primes.begin(); p != primes.end(); p++) 
        {
            if (*p >= cap) 
                break;

            if (i % *p == 0) 
            {
                isprime = false;
                break;
            }
        }

        if(isprime) 
            primes.push_back(i);
    }

    t = clock() - t;

    cout << ((float)t)/CLOCKS_PER_SEC << endl;

    ll int T,N,M;

    cin >> T;

    for (ll int t = 0; t < T; t++)
    {
        cin >> M >> N;
        if (M < 2) 
            M = 2;

        ll int cap = sqrt(N) + 1;

        set<ll int> notprime;
        notprime.clear();

        vector<ll int> :: iterator p;

        for (p = primes.begin(); p != primes.end(); p++) {

            if (*p >= cap) 
                break;

            ll int start;

            if (*p >= M) 
                start = (*p)*2;
            else 
                start = M + ((*p - M % *p) % *p);

            for (ll int j = start; j <= N; j += *p)
                notprime.insert(j);
        }

        for (ll int i = M; i <= N; i++) 
        {
            if (notprime.count(i) == 0)
                cout << i << endl;
        }

    }
    return 0;
}