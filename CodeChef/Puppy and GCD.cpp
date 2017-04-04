/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll i, j, count = 0, n, d, bound;
		cin >> n >> d;
		bound = n/d;
		count += bound;
		for(i = 2; i <= bound; i++)
		{
			count += bound - bound/i - 1;
		}
		cout << count << endl;
	}
	return 0;
}
