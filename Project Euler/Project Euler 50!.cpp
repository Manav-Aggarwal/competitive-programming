/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 1000000;
ll arr[1000001];
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
	for(i = 3; i <= 10000; i+=2)
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
	ll i, j, mostTerms = 2, sum, length, largestPrime = 2;
	for(length = mostTerms - 1; length < primes.size(); length++)
	{
		for(j = 0; j < primes.size() - length; j++)
		{
			sum = 0;
			for(i = j; i < j + length; i++)
			{
				sum += primes[i];
				if(sum >= 1000000)
				{
					sum = 0;
					break;
				}
			}
			if(arr[sum] && length > mostTerms)
			{
				mostTerms = length;
				largestPrime = sum;
			}
		}
	}
	cout << largestPrime;
	return 0;
}
