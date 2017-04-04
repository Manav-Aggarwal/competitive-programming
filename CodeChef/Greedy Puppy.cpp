/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k, i, maxCoins = 0, rem;
		cin >> n >> k;
		for(i = 1; i <= k; i++)
		{
			maxCoins = max(maxCoins, n%i);
		}
		cout << maxCoins << endl;
	}
	return 0;
}
