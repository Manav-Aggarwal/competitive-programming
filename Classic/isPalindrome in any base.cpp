/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll isPalin(ll num, ll base)
{
	ll reversed = 0;
	ll n = num;
	while(n)
	{
		reversed = base*reversed + n % base;
		n /= base;
	}
	return num == reversed; 
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << isPalin(585, 2);
	return 0;
}
