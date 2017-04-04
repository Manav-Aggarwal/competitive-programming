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
		ll n, k, i, tmp, ops = 0, dist1, dist2;
		cin >> n >> k;
		ll arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
			if(arr[i] % k == 0)
			{
				continue;
			}
			if(arr[i] < k)
			{
				ops += k - arr[i];
				arr[i] = k;
			}
			else
			{
				tmp = arr[i]/k;	
				dist1 = abs(arr[i] - tmp*k);
				dist2 = abs(arr[i] - (tmp+1)*k);
				ops += min(dist1, dist2);
			}
		}
		cout << ops << endl;
	}
	return 0;
}
