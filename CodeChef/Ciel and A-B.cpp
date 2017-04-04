/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b, r;
	cin >> a >> b;
	a = a-b;
	r = a % 10;
	if(a - 1 == 0)
	{
		cout << 5 << endl;
		return 0;
	}
	if(r != 0)
	{
		cout << a - 1 << endl;
	}
	else
	{
		cout << a + 1 << endl;
	}
	return 0;
}
