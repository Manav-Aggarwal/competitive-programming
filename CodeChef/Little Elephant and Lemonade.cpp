#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long P[10001], bottles[101][101];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long n, m, i, j, C;
		cin >> n >> m;
		for(i = 0; i < m; i++)
		{
			cin >> P[i];
		}
		for(i = 0; i < n; i++)
		{
			cin >> C;
			for(j = 0; j < C; j++)
			{
				cin >> bottles[i][j];
			}
		}
	}
	return 0;
}
