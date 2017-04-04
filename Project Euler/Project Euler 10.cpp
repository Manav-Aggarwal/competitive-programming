/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll M = 2000000;
ll arr[2000001];
void sieveOfEratosthenes()
{
	ll i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i < sqrt(M); i++)
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
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i, sum = 0;
	for(i = 2; i <= M; i++)
	{
		if(arr[i])
		{
			sum += i;
		}
	}
	cout << sum;
	return 0;
}
