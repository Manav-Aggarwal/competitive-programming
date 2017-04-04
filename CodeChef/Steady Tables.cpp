/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll limit = 4000, mod = 1000000000;
int C[limit+1][limit+1];
int binomialCoeff(int n, int k)
{
    int i, j;
 
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
 
    return C[n][k] % mod;
}

ll composition(ll n, ll k)
{
	return C[n+k-1][k-1];
}

vector<vector<ll> > nums;
vector<ll> combs;
ll modulo(ll base, ll exponent)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	binomialCoeff(limit, limit);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, m, i, j, productNum, productDenom;
		double sum = 0;
		cin >> n >> m;
		ll compositions[m+1];
		for(i = 0; i <= m; i++)
		{
			compositions[i] = composition(i, m);
		}
		if(n == 1)
		{
			for(i = 0; i <= m; i++)
			{
				sum = ((ll)sum + compositions[i]) % mod;
			}
			cout << sum << endl;
			break;
		}
		if(m == 1)
		{
			cout << compositions[m] << endl;
			break;
		}
		for(i = 0; i <= m; i++)
		{
			productNum = modulo(compositions[i], n+m);
			productDenom = 1;
			for(j = 0; j <= m; j++)
			{
				if(j != i)
				{
					productDenom = (productDenom * (compositions[i]-compositions[j])) % mod;
				}
			}
			if(productDenom == 0)
			{
				productDenom = 1;
			}
			sum = fmod(sum + ((double)productNum/productDenom), mod) ;
		}
		cout << (ll)sum << endl;
	}
	return 0;
}
