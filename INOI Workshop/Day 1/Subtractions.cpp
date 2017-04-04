/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, a, b;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		ll cnt = 0;
		cin >> a >> b;
		while(!(a == 0 || b == 0))
		{
			if(a > b)
			{
				a -= b;
				cnt++;
			}
			else 
			{
				b -= a;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
