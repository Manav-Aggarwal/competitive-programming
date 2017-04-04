/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll M = 1000000;
bool arr[1000001];
vector<ll> primes;
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 0; i <= M; i++)
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
	for(i = 11; i <= M; i++)
	{
		if(arr[i])
		{
			primes.push_back(i);
		}
	}
}

bool isTruncable(ll num)
{
	ll f, l, numcpy = num, numcpy1 = num;
	bool isTruncable = true;
	f = numcpy/10; l = numcpy % (ll)(pow(10, floor(log(numcpy)/log(10))));
	while(f && l)
	{
		if(!arr[f] || (!arr[l]))
		{
			isTruncable = false;
			break;
		}
		f = numcpy/10; 
		l = numcpy1 % (ll)(pow(10, floor(log(numcpy1)/log(10))));
		numcpy = f;
		numcpy1 = l;
	}
	return isTruncable;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	vector<ll> truncablePrimes;
	ll i, sum = 0;
	for(i = 0; i < primes.size(); i++)
	{
		if(isTruncable(primes[i]))
		{
			truncablePrimes.push_back(primes[i]);
		}
	}
	for(i = 0; i < truncablePrimes.size(); i++)
	{
		cout << truncablePrimes[i] << endl;
		sum += truncablePrimes[i];
	}
	cout << "Sum : " << sum;
	return 0;
}
