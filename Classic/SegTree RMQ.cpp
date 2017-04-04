/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 111111
#define INF 0x7fffffff
ll n, *segTree, arr[MAXN];

ll updateTreeUtil(ll ss, ll se, ll index, ll i, ll val)
{
	if(ss > se)
	{
		return INF;
	}
	else if(ss == i && se == i)
	{
		segTree[index] = val;
		return segTree[index];
	}
	else if(ss != se)
	{
		ll mid = (ss + se)/2;
		segTree[index] = min(updateTreeUtil(ss, mid, 2*index, i, val), updateTreeUtil(mid+1, se, 2*index + 1, i, val));		
		return segTree[index];
	}
	else
	{
		return segTree[index];
	}
}
ll updateTree(ll i, ll val)
{
	arr[i] = val;
	return updateTreeUtil(1, n, 1, i, val);
}
ll getMinUtil(ll ss, ll se, ll l, ll r, ll index)
{
	if(l <= ss && se <= r)
	{
		return segTree[index];
	}
	else if(se < l || ss > r)
	{
		return INF;
	}
	else
	{
		ll mid = (ss + se)/2;
		segTree[index] = min(getMinUtil(ss, mid, l, r, 2*index), getMinUtil(mid+1, se, l, r, 2*index + 1));
		return segTree[index];
	}
}
ll getMin(ll l, ll r)
{
	return getMinUtil(1, n, l, r, 1);
}
ll constructUtil(ll *tree, ll ss, ll se, ll index)
{
	if(ss == se)
	{
		tree[index] = arr[ss];
		return tree[index];
	}
	else
	{
		ll mid = (ss+se)/2;
		tree[index] = min(constructUtil(tree, ss, mid, 2*index), constructUtil(tree, mid+1, se, 2*index + 1));
		return tree[index];
	}
}
ll *constructSegTree()
{
	ll x = ceil(log2(n));
	ll maxSize = 2*(pow(2, x))-1;
	ll *tree = new ll[maxSize];
	constructUtil(tree, 1, n, 1);
	return tree;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	ll i;
	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	segTree = constructSegTree();
	cout << getMin(1, n) << endl;
	updateTree(5, 1);
	cout << getMin(1, n) << endl;
	updateTree(5, 101);
	cout << getMin(1, n) << endl;
	return 0;
}
