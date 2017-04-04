/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<pair<ll, ll>, ll> coords;
	ll num = 0, i;
	for(i = 0; i <= 10000; i++)
	{
		coords[make_pair(i, i)] = num;
		if(num&1)
			num += 3;
		else
		 	num++;
	}
	num = 2;
	for(i = 0; i <= 10000; i++)
	{
		coords[make_pair(i+2, i)] = num;
		if(num&1)
			num += 3;
		else
		 	num++;
	}
	ll n;
	cin >> n;
	while(n--)
	{
		ll x, y;
		cin >> x >> y;
		if(x == 0 && y == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			if(coords[make_pair(x, y)] == 0)
			{
				cout << "No Number" << endl;
			}
			else
			{
				cout << coords[make_pair(x, y)] << endl;
			}
			
		}
	}
	return 0;
}
