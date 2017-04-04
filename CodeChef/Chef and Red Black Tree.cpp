/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int rootColor = 0;
ll getLCA(ll x, ll y)
{
	while(x!=y)
	{
		if(x > y)
		{
			x >>= 1;	
		}
		if(y > x)
		{
			y >>= 1;
		}
	}
	return x;
}
void flipColor()
{
	rootColor ^= 1;	
}
ll lg(ll n)
{
	ll j = 0;
	while(n > 0)
	{
		n >>= 1; 
		j++;
	}
	return j;
}
ll getSameColor(ll x)
{
	ll k = lg(x);
	return k/2 + k % 2;
}
ll getDiffColor(ll x)
{
	ll k = lg(x);
	return k/2;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll Q;
	cin >> Q;
	string s;
	while(Q--)
	{
		cin >> s;
		char c = s[1];
		if(c == 'i')
		{
			flipColor();
		}
		else
		{
			ll x, y, total = 0, l, r, root = 1;
			cin >> x >> y;
			ll lca = getLCA(x, y);
			if((rootColor == 0 && c == 'b') || (rootColor == 1 && c == 'r'))
			{
				l = getSameColor(x) - getSameColor(lca);
				r = getSameColor(y) - getSameColor(lca);
				total = l + r + lg(lca) % 2;
			}
			else
			{
				l = getDiffColor(x) - getDiffColor(lca);
				r = getDiffColor(y) - getDiffColor(lca);
				total += l + r + 1 - (lg(lca) % 2);
			}
			cout << total << endl;
		}
	}
	return 0;
}
