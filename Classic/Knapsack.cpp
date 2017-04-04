#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void knpsck(long long weights[], long long vals[], int n, int Capacity)
{
	long long knapsack[n+1][Capacity+1];
	long long i, w, t;
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= Capacity; w++)
		{
			if(i == 0 || w == 0)
			{
				knapsack[i][w] = 0;
			}
			else
			{
				if(weights[i - 1] > w)
				{
					knapsack[i][w] = knapsack[i-1][w];
				}
				else
				{
					t = knapsack[i][w] = max(knapsack[i-1][w], vals[i-1] + knapsack[i-1][w - weights[i-1]]);
				}
			}
		}
	}
	cout << knapsack[n][Capacity] << endl;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, n, i;
	cin >> x >> n;
	long long weights[n], vals[n];
	for(i = 0; i < n; i++)
	{
		cin >> weights[i];
		cin >> vals[i];
	}
	knpsck(weights, vals, n, x);
	return 0;
}
