/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isAmicable[10001];
ll sumOfDivisors(ll n)
{
	ll sum = 1;
	for(ll i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			sum += i;
			sum += n/i;
		}
	}
	return sum;
}

int main()
{	
	ll i, k, sum = 0;
	for(i = 0; i < 10000; i++)
	{
		if(isAmicable[i])
		{
			continue;
		}
		k = sumOfDivisors(i);
		if(sumOfDivisors(k) == i && i != k)
		{
			isAmicable[i] = true;
			if(k <= 10000)
			{
				isAmicable[k] = true;
			}
		}
	}
	for(i = 0; i <= 10000; i++)
	{
		if(isAmicable[i])
		{
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
