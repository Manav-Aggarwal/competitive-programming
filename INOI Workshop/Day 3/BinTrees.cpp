/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t, mod = 1e9 + 7, i, j, k;
	ll count[301];
	count[0] = 1; count[1] = 1;
	for(i = 2; i <= 300; i++)
	{
		count[i] = 1;
		for(j = i + 2; j <= 2*i; j++)
		{
			count[i] *= j;
			count[i] %= mod;
		}
	}
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		cout << count[n] << endl;
	}
	return 0;
}
