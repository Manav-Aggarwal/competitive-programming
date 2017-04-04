/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 1000000, sum = 0;
ll phi[1000001];
void sieveOfEratosthenes()
{
	ll i, j;
	for(i = 0; i <= M; i++)
	{
		phi[i] = i;
	}
	
	for(i = 2; i <= M; i++)
	{
		if(phi[i] == i)
		{
			for(j = i; j <= M; j+=i)
			{
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
		sum += phi[i];
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	cout << sum;
	return 0;
}
