/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll dists[1001][1001];
pair<ll, ll> arr[1001];
ll query(ll l, ll r)
{
	ll maxD = 0, i, j, dist;
	for(i = l; i < r; i++)
	{
		for(j = l + 1; j <= r; j++)
		{
			dist = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
			maxD = max(maxD, dist);
		}
	}
	return maxD;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, x, y, Q, l, r, index;
	cin >> n;
	char wut;
	for(i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		arr[i] = make_pair(x, y);
	}
	for(i = 0; i < n-1; i++)
	{
		dists[i][i] = 0;
		for(j = i+1; j < n; j++)
		{
			dists[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
		}
	}
	cin >> Q;
	for(i = 0; i < Q; i++)
	{
		cin >> wut;
		if(wut == 'Q')
		{
			cin >> l;
			cin >> r;
			cout << query(l, r);
		}
		else
		{
			cin >> index;
			cin >> x;
			cin >> y;
			arr[index].first = x;
			arr[index].second = y;
		}
	}
	return 0;
}
