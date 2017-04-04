/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll numTrailingFact(ll n)
{
	ll count = 0, k = 5;
	while(n/k > 0)
	{
		count += n/k;
		k*=5;
	}
	return count;
}
ll lastDig(ll b, ll p)
{
	if(p == 0)
	{
		return 1;
	}
	map<ll, bool> digs;
	vector<ll> arr;
	ll base = b;
	b = b % 10;
	while(true)
	{
		if(!digs[b])
		{
			arr.push_back(b);
			digs[b] = true;
			b *= base;
			b = b % 10;
		}
		else
		{
			break;
		}
	}
	ll len = arr.size();
	return arr[(p-1) % len];
}
bool isPyscho(ll n)
{
	if(n == 0 || n == 1)
	{
		return false;
	}
	ll i, even = 0, odd = 0, count;
	for(i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			count = 0;
			while(n % i == 0) 
			{
				count++;
				n /= i;
			}
			if(count&1)
			{
				odd++;
			}
			else
			{
				even++;
			}
		}
	}
	if(n > 1) odd++;
	if(even > odd)
	{
		return true;
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll k, b, p, num;
		cin >> k >> b >> p;
		num = numTrailingFact(k);
		num *= lastDig(b, p);
		if(isPyscho(num))
		{
			cout << "Psycho Number" << endl;
		}
		else
		{
			cout << "Ordinary Number" << endl;
		}
	}
	return 0;
}
