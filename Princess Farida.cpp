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
	for(ll a = 1; a <= t; a++)
	{
		ll n;
		cin >> n;
		ll arr[n], excl = 0, incl, sum;
		for(ll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		incl = arr[0];
		for(ll i = 1; i < n; i++)
		{
			sum = max(incl, excl);
			incl = excl + arr[i];
			excl = sum;
		}
		cout << "Case " << a << ": " << max(incl, excl) << endl;
	}
	return 0;
}
