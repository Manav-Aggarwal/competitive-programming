/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 7654321;
ll arr[7654322];
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
}
bool isPandigitalN(ll num)
{
	set<ll> digits;
	ll size = (ll)(log(num)/log(10) + 1);
	while(num)
	{
		if(digits.count(num%10) || num % 10 > size || num % 10 == 0)
		{
			return false;
		}
		digits.insert(num%10);
		num /= 10;
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i, maxNum = 0;
	for(i = 1234567; i < 7654321; i+=2)
	{
		if(arr[i] && isPandigitalN(i) && i > maxNum)
		{
			maxNum = i;
		}
	}
	cout << maxNum;
	return 0;
}
