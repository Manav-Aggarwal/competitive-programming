/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll int
#define INF 99999
ll dp[1 << 17], n, curr[17], final[17];
ll findMoves(ll mask, ll cnt)
{
	if(cnt == n)
		return dp[mask] = 0;
	else if(dp[mask] != -1)
		return dp[mask];
	else
	{
		ll moves = INF;
		for(ll i = 0; i < n; i++)
		{
			if(!(mask & (1 << i)))
				moves = min(moves, findMoves(mask | (1 << i), cnt+1) + abs(cnt - i) + abs(final[cnt] - curr[i]));
		}
		return dp[mask] = moves;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		ll i, j, x, y;
		cin >> n;
		if(n == 0)
			break;
		memset(dp, -1, sizeof(dp));
		for(i = 0; i < n; i++)
		{
			cin >> curr[i];
		}
		for(i = 0; i < n; i++)
		{
			cin >> final[i];
		}
		cout << findMoves(0, 0) << endl;
	}
	return 0;
}
