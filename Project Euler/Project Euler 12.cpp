/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<ll> primes;
void sieve()
{
	ll M = 100000, i, j;
	ll arr[M+1];
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;	
	}	
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(M); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j <= M; j+= i)
			{
				arr[j] = 0;
			}
		}
	}
	for(i = 0; i <= M; i++)
	{
		if(arr[i] == 1)
		{
			primes.push_back(i);
		}
	}
}
ll NoOfDivisors(ll n)
{
	ll d = 1, i = 0, expo;
	while(primes[i] <= n)
	{
		if(primes[i] * primes[i] > n)
		{
			return 2*d;
		}
		expo = 0;
		while(n % primes[i] == 0)
		{
			expo++;
			n/= primes[i];
		}
		d *= expo + 1;
		if(n == 1)
		{
			return d;
		}
		i++;
	}
	return d;
}

int main()
{	
	sieve();
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i = 2, count = 0, nd = 2, n1d = 2;
	while(count < 500)
	{
		if(i & 1)
		{
			n1d = NoOfDivisors((i+1)/2);
			count = nd * n1d;
		}
		else
		{
			nd = NoOfDivisors(i+1);
			count = nd * n1d;
		}
		i++;
	}

	cout << ( i * (i-1) )/2;
	return 0;
}
