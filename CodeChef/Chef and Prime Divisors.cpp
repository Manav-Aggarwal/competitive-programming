/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll A, B, i;
		cin >> A >> B;
		while(A != 1 && B != 1)
		{
			A = gcd(A, B);
			B = B/A;
		}
		A = gcd(A, B);
		B = B/A;
		if(A == B)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
