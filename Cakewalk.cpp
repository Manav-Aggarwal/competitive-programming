/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
ll gcd(ll a, ll b) 
{
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
int main() {
 
    ll t;
    cin >> t;
    while(t--)
    {
    	ll s, e1, e2, v1, v2, cmn = 0, lcmv;
    	cin >> s >> e1 >> e2 >> v1 >> v2;
    	e1 -= s; e2 -= s;
    	if(v1 > 0 && v2 < 0 || (v1 < 0 && v2 > 0))
    	{
    		cout << 1 << endl;
    		continue;
		}
		e1 = abs(e1); e2 = abs(e2);
		v1 = abs(v1); v2 = abs(v2);
    	lcmv = lcm(v1, v2);
    	cmn = (min(e1, e2))/ lcmv;
    	cout << cmn + 1 << endl;	
	}
    return 0;
}
