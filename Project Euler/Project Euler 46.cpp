/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 100000;
ll arr[100001];
vector<ll> oddComposites;
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
		if(arr[i] == 0)
		{
			oddComposites.push_back(i);
		}
		else
		{
			primes.push_back(i);
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i, j, num = 0;
	double tmp;
	bool found;
	for(i = 0; i < oddComposites.size(); i++)
	{
		if(oddComposites[i] == 5777)
		{
			oddComposites[i] == 5777;
		}
		found = false;
		for(j = 0; j < oddComposites[i] && j < primes.size(); j++)
		{
			tmp = ( oddComposites[i] - primes[j] )/2;
			if(sqrt(tmp) == (ll)sqrt((tmp)))
			{
				found = true;
				break;
			}
		}
		if(!found)
		{
			num  = oddComposites[i];
			break;
		}
	
	}
	cout << num;
	return 0;
}
