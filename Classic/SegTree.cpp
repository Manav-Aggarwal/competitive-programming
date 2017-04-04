#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll getMid(ll s, ll e)
{
	return (s + (e-s)/2);
}
ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
	if(qs <= ss && qe >= se)
	{
		return st[index];
	}
	if(se < qs || ss > qe)
	{
		return 0;
	}
	ll mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*index + 1) + getSumUtil(st, mid+1, se, qs, qe, 2*index + 2);
}
ll getSum(ll *st, ll n, ll qs, ll qe)
{
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}
void updateValUtil(ll *st, ll index, ll diff, ll ss, ll se)
{
	st[index] += diff;
	if(ss != se)
	{
		ll mid = getMid(ss, se);
		updateValUtil(st, 2*index + 1, diff, ss, mid);
		updateValUtil(st, 2*index + 2, diff, mid + 1, se);
	}
}
void updateVal(ll *st, ll index, ll arr[], ll n, ll newVal)
{
	ll diff = newVal - arr[index];
	arr[index] = newVal;
	updateValUtil(st, index, diff, 0, n-1);
}
ll constructSegTree(ll arr[], ll ss, ll se, ll *st, ll si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	ll mid = getMid(ss, se);
	st[si] = constructSegTree(arr, ss, mid, st, 2*si + 1) + constructSegTree(arr, mid + 1, se, st, 2*si + 2);
	return st[si];
}
ll *SegMake(ll arr[], ll n)
{
	ll x = (ll)(ceil(log2(n)));
	ll max_size = 2*(ll)(pow(2, x)) - 1;
	ll *st = new ll[max_size];
	constructSegTree(arr, 0, n-1, st, 0);
	return st;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	return 0;
}
