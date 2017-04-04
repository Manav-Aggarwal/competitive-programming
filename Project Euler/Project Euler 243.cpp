/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll M = 100;
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
ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;}
ll resilience(ll d, ll n)
{
	ll i, phi;
	phi = d;
	for(i = 0; i < n; i++)
	{
		phi = (phi * (primes[i]-1))/primes[i];
	}
	return phi;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	double lim = 15499/94744.0, ratio;
	ll i = 1, res = resilience(2, 1), prod = 2;
	ratio = (double)res/(prod-1);
	while(ratio >= lim)
	{
		i++;
		prod *= primes[i-1];
		res = resilience(prod, i);
		ratio = (double)res/(prod-1);
	}
	prod/=primes[i-1];
	res = resilience(prod, i-1);
	ratio = (double)res/(prod-1);
	while(ratio >= lim)
	{
		prod *=2;
		res = resilience(prod, i-1);
		ratio = (double)res/(prod-1);
	}
	cout << res << "/" << prod << " " << ratio;
	return 0;
}
