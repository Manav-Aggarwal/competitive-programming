/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll arr[1000011], sorted[1000011];
unordered_map<ll, ll> pos;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		bool flag = true;
		ll n, i;
		cin >> n;
		for(i = 1; i <= n; i++)
		{
			cin >> arr[i];
			sorted[i] = arr[i];
		}
		sort(sorted+1, sorted+n+1);
		for(i = 1; i <= n; i++)
		{
			pos[sorted[i]] = i;
		}
		for(i = 1; i <= n; i++)
		{
			if(abs(pos[arr[i]] - i) > 1)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
