/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 10000;
ll arr[10001];
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
	ll num = 10, i, j;
	while(true)
	{
		ll ways[num+1];
		for(i = 0; i <= num; i++)
		{
			ways[i] = 0;
		}
		ways[0] = 1;
		for(i = 0; primes[i] <= num; i++)
		{
			for(j = primes[i]; j <= num; j++)
			{
				ways[j] += ways[j - primes[i]]; 
			}
		}
		if(ways[num] > 5000)
		{
			break;
		}
		num++;
	}
	cout << num;
	return 0;
}
