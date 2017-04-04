/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b, i, j, k, l, lower, higher, distinct = 0, factor, x;
	cin >> lower >> higher;
	bool grid[higher+1][higher+1];
	vector<ll> rpt; 
	for(i = lower; i <= higher; i++)
	{
		for(j = lower; j <= higher; j++)
		{
			grid[i][j] = false;
		}
	}
	for(i = lower; i <= higher; i++)
	{
		if(i == 64)
		{
			i = 64;
		}
		k = lower; rpt.clear();
		while(pow(i, k-1) <= higher)
		{
			rpt.push_back(pow(i, k-1));
			k++;
		}
		for(j = lower; j <= higher; j++)
		{
			if(j-lower < rpt.size() && i * rpt[j-lower] <= higher)
			{
				k = lower;
				while(k <= (higher/(j)))
				{
	 				grid[(ll)pow(i, j)][k] = true;
					k++;
				}
				x = 2;
				while(x < j)
				{
					k = 0;
					while(k <= (higher/(j)) * x)
					{
	 					grid[(ll)pow(i, x)][k] = true;
						k+= x;
					}
					x++;
				}
				
			}
			if(grid[i][j])
			{
				continue;
			}
 			grid[i][j] = true;
			distinct++;
		}
		i = i;
	}
	cout << distinct;
	return 0;
}
