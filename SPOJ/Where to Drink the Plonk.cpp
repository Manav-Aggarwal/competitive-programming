/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define x first
#define y second

bool wayToSort(pii a, pii b)
{
	return (a.x == b.x) ? a,y < b.y : a.x < b.x;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, i;
		pii house;
		cin >> n;
		pii houses[n];
		for(i = 0; i < n; i++)
		{
			cin >> house.x >> house.y;
			houses[i] = house;
		}
		sort(houses, houses + n, wayToSort);
	}
	return 0;
}
