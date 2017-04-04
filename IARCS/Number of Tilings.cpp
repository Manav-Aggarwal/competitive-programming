/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000001

ll f[M], g[M];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	f[1] = 1, f[2] = 2, g[1] = 1, g[2] = 2;
	ll n, i;
	cin >> n;
	for(i = 3; i <= n; i++)
	{
		f[i] = f[i-1] + f[i-2] + 2*g[i-2];
		g[i] = f[i-1] + g[i-1];
		f[i] %= 10000;
		g[i] %= 10000;
	}
	cout << f[n];
	return 0;
}
