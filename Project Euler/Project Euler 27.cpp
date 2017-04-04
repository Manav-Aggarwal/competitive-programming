/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<ll> possibleB;
ll M = 2000;
ll arr[2001];
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
	for(i = 2; i < 1000; i++)
	{
		if(arr[i])
		{
			possibleB.push_back(i);
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll b, a, n, product = 1, largestN = 0, val;
	for(b = 0; b < possibleB.size(); b++)
	{
		for(a = -1000; a < 1000; a++)
		{
			n = 0;
			val = abs( (n*n) + (a*n) + possibleB[b] );
			while((arr[val]) ) 
			{
				val = abs( (n*n) + (a*n) + possibleB[b] );
				n++;
			}
			if(largestN < n)
			{
				largestN = n;
				product = a * possibleB[b];
			}
		}
	}
	cout << product;
	return 0;
}
