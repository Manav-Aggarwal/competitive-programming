/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define mp make_pair
#define price first
#define startT second.first
#define endT second.second
bool wayToSort(piii a, piii b) {return a.startT < b.startT;}
ll dp[10011];
ll binSearch(piii orders[], ll pos, ll n, ll start)
{
	if(pos > n)
	{
		return -1;
	}
	ll mid = (pos + n)/2;
	if(pos == n)
	{
		if(orders[n].startT >= start)
			return pos;
		else
			return -1;
	}
	if(orders[mid].startT >= start)
	{
		return binSearch(orders, pos, mid, start);
	}
	else
	{
		return binSearch(orders, mid+1, n, start);
	}
}
ll getMax(piii orders[], ll pos, ll n, ll start)
{
	if(pos > n)
	{
		return dp[pos] = 0;
	}
	else if(orders[pos].startT < start)
	{
		pos = binSearch(orders, pos+1, n, start);
		if(pos == -1)
			return 0;
	}
	else if(dp[pos] > -1)
	{
		return dp[pos];
	}
	ll p = getMax(orders, pos+1, n, start);
	ll q = getMax(orders, pos+1, n, orders[pos].endT) + orders[pos].price;
	return dp[pos] = max(p, q);
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{	
		ll n, i, d;
		cin >> n;
		piii orders[n+1];
		for(i = 1; i <= n; i++)
		{
			cin >> orders[i].startT >> d >> orders[i].price;
			orders[i].endT = orders[i].startT + d;
		}
		sort(orders + 1, orders + n + 1, wayToSort);
		memset(dp, -1, sizeof(dp));
		cout << getMax(orders, 1, n+1, orders[1].startT) << endl;
	}
	return 0;
}
