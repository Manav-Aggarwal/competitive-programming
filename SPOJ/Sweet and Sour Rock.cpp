/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll dp[222][222], countT[222];
ll calc(string rock, ll s, ll e, ll num1s)
{
	ll l1, l2;
	if(s > e || num1s <= 0)
	{
		return dp[s][e] = 0;
	}
	if(s == e)
	{
		return dp[s][e] = num1s;
	}
	if(dp[s][e] != -1)
	{
		return dp[s][e];
	}
	if(num1s > e-s+1 - num1s)
	{
		return dp[s][e] = e-s+1;
	}
	else
	{
		for(ll k = s; k < e; k++)
		{
			dp[s][e] = max(dp[s][e], calc(rock, s, k, countT[k] - countT[s-1]) + calc(rock, k+1, e, countT[e] - countT[k]));
		}
		return dp[s][e];
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, i, num1s = 0;
		string rock, temp = "0";
		cin >> n >> rock;
		rock = temp + rock;
		countT[0] = 0;
		for(i = 1; i <= n; i++)
		{
			if(rock[i] == '1')
			{
				countT[i] = countT[i-1]+1;
			}
			else
			{
				countT[i] = countT[i-1];
 			}
		}
		num1s = countT[n];
		memset(dp, -1, sizeof(dp));
		cout << calc(rock, 1, n, num1s) << endl;
	}
	return 0;
}
