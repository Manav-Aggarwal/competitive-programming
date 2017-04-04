/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll int
#define MAX 2000001
ll knapsack[2][MAX];
ll vals[501], weights[501];
ll findKnapsack(ll k, ll n)
{
	ll prev = 1, curr = 0, i = -1, j;
	while(++i <= n)
	{
		j = -1;
		while(++j <= k)
		{
			if(i == 0 || j == 0)
			{
				knapsack[curr][j] = 0;
			}
			else if(weights[i-1] > j)
				knapsack[curr][j] = knapsack[prev][j];
			else
				knapsack[curr][j] = max(knapsack[prev][j], vals[i-1] + knapsack[prev][j-weights[i-1]]);
		}
		prev = curr;
		curr = !curr;
	}
	return knapsack[prev][k];
}
int main()
{	
	//ios_base::sync_with_stdio(false); cin.tie(0);
	ll k, n, i;
	scanf("%d", &k);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &vals[i]);
		scanf("%d", &weights[i]);
	}
	printf("%d\n", findKnapsack(k, n));
	return 0;
}
