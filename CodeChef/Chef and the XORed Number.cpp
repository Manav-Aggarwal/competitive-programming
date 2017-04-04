/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool containsAllOnes(ll n)
{
	while(n > 0)
	{
		if(!(n&1))
		{
			return false;
		}
		n >>= 1;
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n;
		if(n == 1)
		{
			cout << 2 << endl;
			continue;
		}
		if(containsAllOnes(n))
		{
			cout << ((n+1) >> 1) - 1 << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
