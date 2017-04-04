/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll SummedPowersOf2[111111]; //Stores the number of powers of 2 added till i
void initPowers()
{
	SummedPowersOf2[0] = 0;
	SummedPowersOf2[1] = 1;
	ll mod = 1e9 + 7, i;
	for(i = 2; i < 111111; i++)
	{
		SummedPowersOf2[i] = (SummedPowersOf2[i-1] * 2) % mod;
	}
	for(i = 2; i < 111111; i++)
	{
		SummedPowersOf2[i] = (SummedPowersOf2[i] + SummedPowersOf2[i-1]) % mod;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	initPowers();
	ll t, mod = 1e9 + 7;
	cin >> t;
	while(t--)
	{
		ll n, i, sum = 0;
		cin >> n;
		ll arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for(i = n-1; i >= 0; i--)
		{
			sum = ( (sum + ( ( arr[i] * ( (SummedPowersOf2[i] - SummedPowersOf2[n - i - 1]) % mod) ) % mod) ) % mod );
			if(sum < 0)
			{
				sum += mod;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
