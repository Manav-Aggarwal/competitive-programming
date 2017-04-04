#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 1111111
ll arr[MAXN], lazy[MAXN], n;
ll stringToNum(string str)
{
	ll i, num = 0;
	for(i = 0; i < str.length(); i++)
	{
		num += (ll)str[i] - '0';
		num*= 10;
	}
	return num/10;
}
string numToString(ll num)
{
	ll i;
	string str = "";
	while(num != 0)
	{
		str += (char)( (num%10) + '0');
		num/=10;
	}
	str = string(str.rbegin(), str.rend());
	return str;
}
string nextRotation(string str)
{
	char f = str[0];
	str = str.substr(1, str.length()-1);
	str += f;
	return str;
}
struct node
{
	node *next;
	ll height;
} vals[MAXN];
ll getMid(ll s, ll e)
{
	return (s + (e-s)/2);
}
ll getMaxUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
	if(ss > se || se < qs || ss > qe)
	{
		return 0;
	}
	if(lazy[index] != 0)
	{
		st[index] += lazy[index];
		if(ss != se)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(ss >= qs && qe >= se)
	{
		return st[index];
	}
	ll mid = getMid(ss, se);
	return max(getMaxUtil(st, ss, mid, qs, qe, 2*index), getMaxUtil(st, mid+1, se, qs, qe, 2*index + 1));
}
ll getMax(ll *st, ll n, ll qs, ll qe)
{
	return getMaxUtil(st, 1, n, qs, qe, 1);
}
void updateValUtil(ll *st, ll l, ll r, ll diff, ll ss, ll se, ll i)
{
	if(lazy[i] != 0)
	{
		st[i] += lazy[i];
		if(ss != se)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i + 1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if (l > se || r < ss || ss > se)
        return;
    if(ss >= l && se <= r)
    {
    	st[i] += diff;
		if(ss != se)
		{
			lazy[2*i] += diff;
			lazy[2*i + 1] += diff;
		}
		return;
	}
	ll mid = getMid(ss, se);
	updateValUtil(st, l, r, diff, ss, mid, 2*i);
	updateValUtil(st, l, r, diff, mid + 1, se, 2*i + 1);
	st[i] = max(st[i*2], st[i*2 +1]);
}
void updateVal(ll *st, ll l, ll r, ll n, ll val)
{
	updateValUtil(st, l, r, val, 1, n, 1);
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
		tree[index] = max(constructUtil(tree, ss, mid, 2*index), constructUtil(tree, mid+1, se, 2*index + 1));
		return tree[index];
	}
}
ll *constructSegTree(ll arr[])
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
	ll i, j;
	string ht;
	for(i = 1; i <= n; i++)
	{
		cin >> ht;
		vals[i].height = stringToNum(ht);
		
		for(j = 1; j < ht.length()-1; j++)
		{
			ht = nextRotation(ht);
			nxt.height = stringToNum(ht);
			curr.next = nxt;
			
		}
	}
	ll *tree = constructSegTree(arr);
	
	return 0;
}
