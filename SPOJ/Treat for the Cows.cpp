/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 2222
ll len, dp[MAXN][MAXN], treats[MAXN];
ll recurMaxM(ll i, ll j)
{
	if(i > j || i < 0 || j > len)
	{
		return 0;
	}
	else
	{
		if(dp[i][j] != -1)
		{
			return dp[i][j];
		}
		ll age = len - j + i;
		return dp[i][j] = max(treats[i]*age + recurMaxM(i+1, j), treats[j]*age + recurMaxM(i, j-1)); 
	}
}
ll maxM(ll treats[], ll n)
{
	ll i, j, t;
	for(i = 0; i <= n; i++)
	{
		dp[i][0] = dp[n][i] = 0;
	}
	for(i = n-1; i >= 0; i--)
	{
		for(j = 0; j < n; j++)
		{
			if(i > j)
			{
				dp[i][j] = 0;
			}
			else
			{
				ll age = n - (j - i + 1) + 1;
				t = dp[i][j] = treats[i]*age + dp[i+1][j];
				if(j > 0)
				{
					t = dp[i][j] = max(dp[i][j], treats[j]*age + dp[i][j-1]);
				}
			}
		}
	}
	return dp[0][n-1];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j;
	for(i = 0; i < MAXN; i++)
	{
		for(j = 0; j < MAXN; j++)
		{
			dp[i][j] = -1;
		}
	}
	cin >> n;
	len = n;
	for(i = 0; i < n; i++)
	{
		cin >> treats[i];
	}
	cout << recurMaxM(0, n-1) << endl; //Use anyone recur or dp
	return 0;
}
