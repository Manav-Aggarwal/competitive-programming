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
		ll h, w, i, j, k, maxN;
		cin >> h >> w;
		ll chamber[h][w];
		for(i = 0; i < h; i++)
		{
			for(j = 0; j < w; j++)
			{
				cin >> chamber[i][j];
			}
		}
		if(h == 1)
		{
			maxN = 0;
			for(i = 0; i < w; i++)
			{
				maxN = max(maxN, chamber[h][i]);
			}
			cout << maxN << endl;
		}
		else
		{
			for(i = h-2; i >= 0; i--)
			{
				for(j = 0; j < w; j++)
				{
					maxN = 0;
					if(j == 0)
					{
						maxN = max(chamber[i+1][j], chamber[i+1][j+1]);
					}
					else if(j == w-1)
					{
						maxN = max(chamber[i+1][j-1], chamber[i+1][j]);
					}
					else
					{
						maxN = max(chamber[i+1][j], max(chamber[i+1][j-1], chamber[i+1][j+1]));
					}
					chamber[i][j] += maxN;
				}
			}
			maxN = 0;
			for(i = 0; i < w; i++)
			{
				maxN = max(maxN, chamber[0][i]);
			}
			cout << maxN << endl;
		}
	}
	return 0;
}
