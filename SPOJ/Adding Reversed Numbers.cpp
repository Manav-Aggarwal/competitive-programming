/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll reversed(ll n)
{
	ll num = 0;
	while(n > 0)
	{
		num = num * 10 + n % 10;
		n /=10;
	}
	return num;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;
	while(n--)
	{
		ll a, b;
		cin >> a >> b;
		cout << reversed(reversed(a) + reversed(b)) << endl;
	}
	return 0;
}
