/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 1000000;
ll arr[1000001], factorCount[1000001];
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
		if(!(i & 1))
		{
			factorCount[i] = 1;
		}
	}
	arr[0] = arr[1] = 0;
	factorCount[2] = 2;
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
	for(i = 3; i <= sqrt(M); i += 2)
	{
		if(arr[i])
		{
			for(j = 2*i; j <= M; j+=i)
			{
				factorCount[j]++;
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i = 210;
	bool notFound = true;
	while(notFound)
	{
		if(factorCount[i] == 4 && factorCount[i+1] == 4 && factorCount[i+2] == 4 && factorCount[i+3] == 4)
		{
			cout << i;
			notFound = false;
			break;
		}
		i++;
	}
	return 0;
}
