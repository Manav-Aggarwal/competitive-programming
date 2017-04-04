/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll ft1[111111], ft2[111111], n;
ll query(ll *fenwickTree, ll index)
{
	ll sum = 0;
	while(index > 0)
	{
		sum += fenwickTree[index];
		index -= index & (-index);
	}
	return sum;
}
ll query(ll index)
{
	return query(ft1, index)*index - query(ft2, index);
}
ll query(ll a, ll b)
{
	return query(b) - query(a-1);
}
void updateTree(ll *fenwickTree, ll index, ll val)
{
	while(index <= n)
	{
		fenwickTree[index] += val;
		index += index & (-index);
	}
}
void updateTree(ll a, ll b, ll val)
{
	updateTree(ft1, a, val);
	updateTree(ft1, b+1, -val);
	updateTree(ft2, a, val*(a-1));
	updateTree(ft2, b+1, (-val)*b);
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll c, i, choice, p, q, v;
		cin >> n >> c;
		for(i = 0; i <= n; i++)
		{
			ft1[i] = ft2[i] = 0;
		}
		for(i = 0; i < c; i++)
		{
			cin >> choice;
			if(choice == 0)
			{
				cin >> p >> q >> v;
				updateTree(p, q, v);
			}
			else
			{
				cin >> p >> q;
				cout << query(p, q) << endl;
			}
		}
	}
	return 0;
}
