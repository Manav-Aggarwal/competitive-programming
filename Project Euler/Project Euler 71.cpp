/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll lim = 1000000, i, j, hcf, num = 0, denom = 1;
	double test = 3.0/7, val;
	for(i = lim; i > 2; i--)
	{
		val = (3*i - 1)/7;
		if(val*denom > num*i)
		{
			denom = i;
			num = val;
		}
	}
	hcf = gcd(num, denom);
	num/=hcf;
	denom/=hcf;
	cout << num << "/" << denom;
	return 0;
}
