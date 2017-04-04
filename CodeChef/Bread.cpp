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
		ll n, k, i;
		cin >> n >> k;
		ll arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		ll availableNow = 0, ans = 0, packsNeeded;
		for(i = 0; i < n; i++)
		{
			packsNeeded = (arr[i] - availableNow)/k + (((arr[i] - availableNow)%k > 0) ? 1 : 0);
			if(packsNeeded < 0)
			{
				packsNeeded = 0;
			}
			availableNow += packsNeeded*k - arr[i];
			ans += packsNeeded;
			if(availableNow > 0)
			{
				availableNow--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
