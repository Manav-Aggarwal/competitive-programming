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
		ll n, i, j, maxDist = 0;
		cin >> n;
		ll arr[n], LMa[n], RMin[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		LMa[0] = arr[0]; RMin[n-1] = arr[n-1];
		for(i = 1; i < n; i++)
		{
			LMa[i] = max(arr[i], LMa[i-1]);
			RMin[n-i-1] = min(arr[n-i-1], RMin[n-i]);
		}
		i = 0, j = 0;
		while(i < n && j < n)
		{
			if(LMa[i] > RMin[j])
			{
				maxDist = max(maxDist, j - i);
				j++;
			}
			else
				i++;
		}
		cout << maxDist << endl;
	}
	return 0;
}
