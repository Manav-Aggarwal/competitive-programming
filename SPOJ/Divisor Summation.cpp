/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll divSums[500001];
const ll M = 500001;
ll arr[M];
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
}
ll divSum(ll n)
{
	if(n == 1)
	{
		return 0;
	}
	if(arr[n])
	{
		return 1;
	}
	ll sum = 1, i;
	for(i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			if(i == n/i)
			{
				sum += i;
			}
			else
				sum += i + n/i;
		}
	}
	return sum;
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
		cout << divSum(n) << endl;
	}
	return 0;
}
