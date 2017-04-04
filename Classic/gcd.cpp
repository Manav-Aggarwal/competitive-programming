/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << gcd(4, 12);
	return 0;
}
