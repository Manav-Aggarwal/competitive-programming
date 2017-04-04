/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 100;
ll arr[101];
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
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll n, i = 0, maxN, lcm = 1; 
	while(lcm <= 1000000 && i < primes.size())
	{
		lcm *= primes[i];
		i++;
	}
	cout << lcm/primes[i-1];
	return 0;
}
