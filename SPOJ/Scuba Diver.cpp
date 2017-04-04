/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 999999999999999

ll oxyCylinder[1011], nitroCylinder[1011], wt[1011], dp[1011][22][80];
ll solve(ll n, ll oxyNeed, ll nitroNeed)
{
	if(dp[n][oxyNeed][nitroNeed] != -1)
	{
		return dp[n][oxyNeed][nitroNeed];
	}
	else if(n == 0 && (oxyNeed || nitroNeed))
	{
		return dp[n][oxyNeed][nitroNeed] = INF;
	}
	else if(!n && !oxyNeed && !nitroNeed)
	{
		return dp[n][oxyNeed][nitroNeed] = 0;
	}
	else
	{
		return dp[n][oxyNeed][nitroNeed] = min(solve(n-1, oxyNeed, nitroNeed), solve(n-1, max(oxyNeed - oxyCylinder[n-1], 0LL), max(nitroNeed - nitroCylinder[n-1], 0LL)) + wt[n-1]);
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll oxyNeed, nitroNeed, n, i;
		cin >> oxyNeed >> nitroNeed >> n;
		for(i = 1; i <= n; i++)
		{
			cin >> oxyCylinder[i] >> nitroCylinder[i] >> wt[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(n+1, oxyNeed, nitroNeed) << endl;
	}
	return 0;
}
