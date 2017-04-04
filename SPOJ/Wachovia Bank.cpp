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
		ll k, m, i, j;
		cin >> k >> m;
		ll weights[m], vals[m];
		for(i = 0; i < m; i++)
		{
			cin >> weights[i] >> vals[i];
		}
		ll knapsack[m+1][k+1];
		for(i = 0; i <= m; i++)
		{
			for(j = 0; j <= k; j++)
			{
				if(i == 0 || j == 0)
				{
					knapsack[i][j] = 0;
				}
				else if(weights[i-1] > j)
					knapsack[i][j] = knapsack[i-1][j];
				else
					knapsack[i][j] = max(knapsack[i-1][j], vals[i-1] + knapsack[i-1][j - weights[i-1]]);
			}
		}
		cout << "Hey stupid robber, you can get " << knapsack[m][k] << "." << endl;
	}
	return 0;
}
