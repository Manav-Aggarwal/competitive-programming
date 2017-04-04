/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll ft[11111], n;
void updateTree(ll index, ll val)
{
	while(index <= n)
	{
		ft[index] += val;
		index += index & (-index);
	}
}
void updateTree(ll l, ll r, ll val)
{
	updateTree(l, val);
	updateTree(r+1, -val);
}
ll query(ll index)
{
	ll sum = 0;
	while(index > 0)
	{
		sum += ft[index];
		index -= index & (-index);
	}
	return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll u, i, q, l, r, val, ind;
		cin >> n >> u;
		for(i = 0; i <= n; i++)
		{
			ft[i] = 0;
		}
		for(i = 0; i < u; i++)
		{
			cin >> l >> r >> val;
			updateTree(l+1, r+1, val);
		}
		cin >> q;
		for(i = 0; i < q; i++)
		{
			cin >> ind;
			cout << query(ind+1) << endl;
		}
	}
	return 0;
}
