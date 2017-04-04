/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mod 1988
#define lim 5111
ll partitions[lim][lim];
void precompute()
{
	ll n, k;
	for(k = 0; k < lim; k++)
	{
		partitions[0][k] = 1;
	}
	for(n = 1; n < lim; n++)
	{
		partitions[n][0] = 0;
	}
	for(n = 1; n < lim; n++)
	{
		for(k = 1; k <= n; k++)
		{
			if(n-k < k)
			{
				partitions[n-k][k] = partitions[n-k][k-1] % mod;
			}
			partitions[n][k] = (partitions[n][k-1] + partitions[n-k][k])%mod;
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	precompute();
	ll n, k, ans;
	cin >> n >> k;
	while(!(n == 0 && k == 0))
	{
		ans = partitions[n][k] - partitions[n][k-1];
		if(ans < 0)
		{
			cout << ans + mod << endl;
		}
		else
		{
			cout << ans % mod << endl;
		}
		cin >> n >> k;
	}

	return 0;
}
