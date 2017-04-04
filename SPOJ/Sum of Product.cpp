/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007

ll sumProd(ll n)
{
	ll sum = 2*n, i;
	sum %= MOD;
	for(i = 2; i*i <= n; i++)
	{
		sum += 2*(n/i) * i;
		sum %= MOD;
	}
	return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		cout << sumProd(n) << endl;
	}
	return 0;
}
