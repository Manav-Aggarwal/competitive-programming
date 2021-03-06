/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 5000;
ll arr[5000];
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

bool isPerm(ll num1, ll num2)
{
	ll arr[10], i;
	for(i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	while(num1)
	{
		arr[num1%10]++;
		num1/=10;
	}
	while(num2)
	{
		arr[num2%10]--;
		num2/=10;
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
	ll lim = sqrt(M), i, j, minN, tmp1, tmp2, phi, phiBest;
	double minRatio = 1e4, ratio, n;
	for(i = 0; i < primes.size() - 1; i++)
	{
		for(j = i + 1; j < primes.size(); j++)
		{
			n = ((double)primes[i]*primes[j]);
			if(n > 1e7)
			{
				break;
			}
			phi = (primes[i]-1)*(primes[j]-1);
			ratio = n/phi;
			if(isPerm(n, phi) && ratio < minRatio)
			{
				minRatio = ratio;
				minN = n;
				phiBest = phi;
				tmp1 = primes[i];
				tmp2 = primes[j];
			}
		}
	}
	cout << minN << " " << phiBest << " " << tmp1 << " " << tmp2;
	return 0;
}
