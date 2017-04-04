/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 46656
#define LMT 216
#define LEN 31623
#define RNG 100032
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x, v , sizeof(x))
#define chkC(x,n) (x[n >> 6] & (1 << ((n >> 1) & 31)))
#define setC(x,n) (x[n >> 6] |= (1 << ((n >> 1) & 31)))
ll base[MAX/64], segment[RNG/64], primes[LEN];

void sieve()
{
    unsigned i, j, k;
    for (i = 3; i < LMT; i += 2)
    {
        if (!chkC(base, i))
        {    
            for (j = i * i, k = i << 1; j < MAX; j += k)
                setC(base, j);
        }
    }
    for (i = 3, j = 0; i < MAX; i += 2)
    {
        if (!chkC(base, i))
            primes[j++] = i;
    }
}
ll segmented_sieve(ll a, ll b)
{
    ll i, j, k, sum = (a <= 2 && 2 <=b )? 2 : 0;
    if (b < 2) 
        return 0;
    if (a < 3) 
        a = 3;
    if (a % 2 == 0) 
        a++;
    mset (segment, 0);
    for (i = 0; sq(primes[i]) <= b; i++)
    {
        j = primes[i] * ((a + primes[i] - 1) / primes[i]);
        if (j % 2 == 0) j += primes[i];
        for (k = primes[i] << 1; j <= b; j += k)
        {
            if (j != primes[i])
                setC(segment, (j - a));
        }
    }
    for (i = 0; i <= b - a; i += 2)
    {
        if (!chkC(segment, i))
    	{
    		j = i + a;
    		while(j)
    		{
    			sum += j % 10;
    			j /= 10;
			}
		}
    }
    return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll n;
	cin >> n;
	while(n--)
	{
		ll a, b, i, num, sum = 0;
		cin >> a >> b;
		cout << segmented_sieve(a, b) << endl;
	}
	return 0;
}
