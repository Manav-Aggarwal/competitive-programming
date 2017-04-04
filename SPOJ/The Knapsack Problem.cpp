/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll knapsack(ll s, ll n, ll vals[], ll weights[])
{
	ll sack[n+1][s+1], i, j;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= s; j++)
		{
			if(i == 0 || j == 0)
			{
				sack[i][j] = 0;
			}
			else if(weights[i-1] > j)
			{
				sack[i][j] = sack[i-1][j];
			}
			else
			{
				sack[i][j] = max(sack[i-1][j], vals[i-1] + sack[i-1][j - weights[i-1]]);
			}
		}
	}
	return sack[n][s];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll s, n, i;
	cin >> s >> n;
	ll weights[n], vals[n];
	for(i = 0; i < n; i++)
	{
		cin >> weights[i] >> vals[i];
	}
	cout << knapsack(s, n, vals, weights) << endl;
	return 0;
}
