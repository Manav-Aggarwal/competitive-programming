/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll n = 1001;
ll grid[1001][1001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i = (n-1)/2, j = (n-1)/2, num = 1, steps = 1, sign = 1, x, sum = 0;
	grid[i][j] = num;
	while(num != n*n)
	{
		for(x = 0; x < steps && num != n*n; x++)
		{
			j += sign;
			num++;
			grid[i][j] = num;
		}
		if(num == n*n)
		{
			break;	
		}
		
		for(x = 0; x < steps; x++)
		{
			num++;
			i += sign;
			grid[i][j] = num;
		}
		steps++;
		sign = -sign;
	}
	for(i = 0, j = 0; i < n && j < n; i++, j++)
	{
		sum += grid[i][j];
		sum += grid[n-i-1][j];
		if(i == n-i-1)
		{
			sum -= grid[i][j];
		}
	}
	cout << sum;
	return 0;
}
