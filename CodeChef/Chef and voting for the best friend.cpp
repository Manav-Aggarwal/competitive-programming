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
		ll n, i, sum = 0, j;
		cin >> n;
		ll arr[n];
		bool poss = true;
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
			if(arr[i] >= n)
			{
				poss = false;
			}
			sum += arr[i];
		}
		if(sum != n || !poss || n == 1)
		{
			cout << -1;
		}
		else
		{
			ll ans[n]; vector<ll> toAdd;
			for(i = 0; i < n; i++)
			{
				ans[i] = -1;
				while(arr[i]--)
				{
					toAdd.push_back(i);
				}
			}
			for(i = 0; ans[i] != -1; i++)
			{
				for(j = 0; j < toAdd.size(); j++)
				{
					if(i != toAdd[j])
					{
						ans[i] = toAdd[j];
						toAdd.erase(toAdd.begin() + j);
					}
				}
			}
			ll temp;
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(i == ans[j] && j == ans[i])
					{
						temp = ans[j];
						ans[j] = ans[i];
						ans[i] = temp;
					}
				}
			}
			for(i = 0; i < n; i++)
			{
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
