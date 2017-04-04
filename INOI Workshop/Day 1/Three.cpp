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
		ll n, i, sum = 0;
		cin >> n;
		ll arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i]/3;
		}
		cout << sum << endl;
	}
	return 0;
}
