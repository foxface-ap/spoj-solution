#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

char check[100000+10];
ll prime[100000+10] , p = 0 ;
int flag[10000000+10] ;

void sieve()
{
    for(int i=2;i<=46361;i++)
    {
        if(check[i] == NULL)
        {
            prime[p++] = i ;
            for(int j=i+i;j<=46341;j+=i) check[j] = 'N' ;
        }
    }
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    sieve();

    int T ;
    scanf("%d",&T);

    for(int cas=1;cas<=T;cas++)
    {
        ll a,b;

        scanf("%lld%lld",&a,&b);

        for(int i=0;i<p;i++)
        {
            ll mod = a%prime[i] ;
            ll idx = prime[i] - mod ;
            if(mod==0) idx = 0 ;

            for(int j=idx;j<=b-a;j+=prime[i])
            {
                if(a+j!=prime[i])
                {
                    flag[j] = cas ;
                }
            }
        }

        for(int i=0;i<=b-a;i++)
        {
            if(flag[i]!=cas)
            {
                printf("%d\n",i+a);
            }
        }
    }

    return 0;
}