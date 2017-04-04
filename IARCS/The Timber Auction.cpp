/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll forest[1111][1111], sums[1111][1111];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll m, n, i, j, C, x1, y1, x2, y2, sum;
	cin >> m >> n;
	for(i = 0; i < max(m, n); i++)
	{
		sums[i][0] = 0;
		sums[0][i] = 0;
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> forest[i][j];
			sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + forest[i][j]; 
		}
	}
	cin >> C;
	for(i = 1; i <= C; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		sum = sums[x2][y2] - sums[x1-1][y2] - sums[x2][y1-1] + sums[x1-1][y1-1];
		printf("%d\n", sum);
	}
	return 0;
}
