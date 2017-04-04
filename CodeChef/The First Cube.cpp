#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll M = 1000000;
ll arr[M+1], mod = 1e9 + 7;
vector<ll> primes;
void sieveOfEratosthenes()
{
	ll i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= cbrt(M); i++)
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
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll t;
	cin >> t;
	while(t--)
	{
		ll N, k, i, j, product = 1, hcf, tmp;
		map<ll, int> factorCount;
		cin >> N;
		ll nums[N];
		for(i = 0; i < N; i++)
		{
			cin >> nums[i];
			for(j = 0; j < primes.size() ; j++)
			{
				if(primes[j] > nums[i])
				{
					break;
				}
				while(nums[i] % primes[j] == 0)
				{
					factorCount[primes[j]]++;
					nums[i] /= primes[j];
				}
			}
			nums[i] %= mod;
		}
		for(i = 0; i < N-1; i++)
		{
			if(nums[i] == 1)
			{
				continue;
			}
			for(j = i+1; j < N; j++)
			{
				hcf = gcd(nums[i], nums[j]);
				if(hcf != 1 && hcf != nums[i])
				{
					factorCount[hcf]++;
					factorCount[nums[i]/hcf]++;
					nums[i] = 1;
				}
			}
		}
		for(i = 0; i < N; i++)
		{
			if(nums[i] != 1)
			{
				tmp = sqrt(nums[i]);
				if(tmp * tmp == nums[i])
				{
					factorCount[tmp]+=2;
					nums[i] = 1;
				}
			}
		}
		for(i = 0; i < N; i++)
		{
			if(nums[i] != 1)
			{
				factorCount[nums[i]]++;
			}
			while(factorCount[nums[i]] % 3 != 0)
			{
				factorCount[nums[i]]++;
			}
		}
		for(i = 0; i < primes.size(); i++)
		{
			while(factorCount[primes[i]] % 3 != 0)
			{
				factorCount[primes[i]]++;
			}
			while(factorCount[primes[i]]--)
			{
				product = (product * primes[i]) % mod;
			}
		}
		for(i = 0; i < N; i++)
		{
			if(nums[i] != 1)
			{
				while(factorCount[nums[i]]--)
				{
					product = (product * nums[i]) % mod;
				}
			}
		}
		cout << product % mod<< endl;
	}
	return 0;
}
