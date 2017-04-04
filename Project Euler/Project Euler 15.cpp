/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j;
	cin >> n;
	n++;
	ll grid[n][n];
	for(i = 0; i < n; i++)
	{
		grid[i][0] = 1;
		grid[0][i] = 1;
	}
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}
	cout << grid[n-1][n-1];
	
	return 0;
}
