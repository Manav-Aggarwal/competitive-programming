/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll num = 1, i, k;
	cin >> k;
	for(i = 2; i < k+1; i++)
	{
		num = lcm(num, i);
	}
	cout << num;
	return 0;
}
