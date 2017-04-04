/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll a,b;
		cin>> a >> b;
		if(a % 2 && b % 2)
		{
			cout << "Vanka" << endl;
		}
		else
		{
			cout << "Tuzik" << endl;
		}
	}
	return 0;
}
