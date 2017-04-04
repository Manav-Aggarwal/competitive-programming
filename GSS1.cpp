#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 5000010
ll t[4*MAX], a[MAX];
ll m, n, qs, qe;
ll buildSegTree(ll arr[], ll start, ll end, ll node)
{
	if(start == end)
	{
		t[node] = arr[start];
		return t[node];
	}
	ll mid = (start + end)/2;
	t[node] = buildSegTree(arr, start, mid, 2*node) + buildSegTree(arr, mid + 1, end, 2*node + 1);
	return t[node];
}
ll query(ll start, ll end, ll node, ll qs, ll qe)
{
	if(qs <= start && qe >= end)
	{
		return t[node];
	}
	if(end < qs || start > qe)
	{
		return 0;
	}
	ll mid = (start + end)/2;
	ll x = query(start, mid, 2*node, qs, qe);
	ll y = query(mid + 1, end, 2*node + 1, qs , qe);
	return x + y;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	buildSegTree(a, 1, n, 1);
	cin >> m;
	while(m--)
	{
		cin >> qs >> qe;
		cout << query(1, n, 1, qs, qe) << endl;
	}
	return 0;
}
