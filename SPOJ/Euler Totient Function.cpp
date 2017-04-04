/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll M =  1000011;
ll arr[M+1];
vector<ll> primes;
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(M); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j <= M; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
	primes.push_back(2);
	for(i = 3; i <= M; i+=2)
	{
		if(arr[i])
		{
			primes.push_back(i);
		}
	}
}
ll resilience(ll n)
{
	ll i, phi = n;
	for(i = 2; i*i <= n; i++)
	{
		if(n % i == 0 && arr[i])
		{
			phi -= phi/i;
			while (n % i == 0) n /= i;
		}
	}
	if(n > 1) phi -= phi/n;
	return phi;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(arr[n])
		{
			cout << n-1 << endl;
		}
		else
			cout << resilience(n) << endl;
	}
	return 0;
}
