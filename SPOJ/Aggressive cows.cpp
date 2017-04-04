/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


bool canBePlaced(ll stalls[], ll n, ll cows, ll dist)
{
	ll lastPos = 0, cowsPlaced = 1, i;
	for(i = 1; i < n; i++)
	{
		if(stalls[i] - stalls[lastPos] >= dist)
		{
			cowsPlaced++;
			lastPos = i;
		}
		if(cowsPlaced == cows)
		{
			return true;
		}
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, c, i, low, high, mid;
		cin >> n >> c;
		ll stalls[n];
		for(i = 0; i < n; i++)
		{
			cin >> stalls[i];
		}
		sort(stalls, stalls+n);
		low = 0, high = stalls[n-1] - stalls[0];
		while(low + 1 < high)
		{
			mid = (low+high)/2;
			if(canBePlaced(stalls, n, c, mid))
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		cout << low << endl;
	}
	return 0;
}
