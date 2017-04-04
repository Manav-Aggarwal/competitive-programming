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
	for(i = 1000; i < M; i++)
	{
		if(arr[i])
		{
			primes.push_back(i);
		}
	}
}

ll containsSame(ll num1, ll num2)
{
	ll arr[10], i;
	for(i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	while(num1)
	{
		arr[num1 % 10]++;
		num1 /=10;
	}
	while(num2)
	{
		arr[num2 % 10]--;
		num2 /= 10;
	}
	for(i = 0; i < 10; i++)
	{
		if(arr[i] != 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i,j, diff;
	for(i = 0; i < primes.size() - 1; i++)
	{
		for(j =  i + 1; j < primes.size(); j++)
		{
			if(containsSame(primes[i], primes[j]))
			{
				diff = primes[j] - primes[i];
				if(containsSame(primes[j] + diff, primes[j]) && primes[j] + diff < 10000 && arr[primes[j] + diff ])
				{
					cout << primes[i] << " " << primes[j] << " " << primes[j] + diff << endl;
				}
			}
		}
	}
	return 0;
}
