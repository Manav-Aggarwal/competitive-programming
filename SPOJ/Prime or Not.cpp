/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll mulmod(ll base, ll exp, ll mod)
{
	ll x = 0, y = base % mod;
	while(exp)
	{
		if(exp&1)
		{
			x = (x+y) % mod;
		}
		y = (y * 2) % mod;
		exp /= 2;
	}
	return x % mod;
}
ll fastMod(ll base, ll exp, ll mod)
{
	ll y = base, result = 1;
	while(exp)
	{
		if(exp&1)
		{
			result = mulmod(result, y, mod);
		}
		y = mulmod(y, y, mod);
		exp /= 2;
	}
	return result % mod;
}

ll isPrime(ll n)
{
	if(n < 2 || (n != 2 && n % 2 == 0))
		return false;
	if(n == 2)
		return true;
	ll s = 0, d, i, x, p = n, tmp, mod;
	n--;
	while(!(n&1))
	{
		n /= 2;
	}
	for(i = 0; i < 5; i++)
	{
		srand (time(NULL));
		x = rand() % (p-1) + 1; tmp = n;
		mod = fastMod(x, tmp, p);
		while(mod != p-1 && mod != 1 && tmp != p-1)
		{
			mod = mulmod(mod, mod, p);
			tmp *= 2;
		}
		if(mod != p-1 && !(tmp&1))
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(isPrime(n))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
