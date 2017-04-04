/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll M = 1000000;
ll arr[1000001];
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
		ll sq = sqrt(n);
		if(sq*sq == n && arr[sq])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
