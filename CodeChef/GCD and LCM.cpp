/* Written By Manav Aggarwal */
#include <stdio.h>
#define ll long long

ll gcd(ll a, ll b) {
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll a, b, hcf, lc;
		cin >> a >> b;
		hcf = gcd(a, b);
		lc = lcm(a, b);
		cout << hcf << " " << lc << endl;
	}
	return 0;
}
