/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<ll> abundant;
bool canBeExpressedAsSumOfAbundant[28124];
ll sumOfDivisors(ll n)
{
	ll sum = 1, sqrtNum = (ll)sqrt(n);
	if(n == sqrtNum *sqrtNum)
	{
		sum += sqrtNum;
		sqrtNum--;
	}
	for(ll i = 2; i <= sqrtNum; i++)
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
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, j, sum = 0;
	for(i = 12; i <= 28123; i++)
	{
		if(sumOfDivisors(i) > i)
		{
			abundant.push_back(i);
		}
	}
	for(i = 0; i < abundant.size(); i++)
	{
		for(j = i; j < abundant.size(); j++)
		{
			if(abundant[i] + abundant[j] < 28124)
			{
				canBeExpressedAsSumOfAbundant[abundant[i] + abundant[j]] = true;
			}
			else
			{
				break;
			}
		}
	}
	for(i = 1; i <= 28123; i++)
	{
		if(!(canBeExpressedAsSumOfAbundant[i]))
		{
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
