/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll dp[1111][1111];
ll getMaxDiff(ll cards[], ll start, ll end, ll turn)
{
	ll sum;
	if(start > end)
	{
		return 0;
	}
	if(dp[start][end] != -1)
	{
		return dp[start][end];
	}
	if(turn == 0)
	{
		sum = max(cards[start] - getMaxDiff(cards, start+1, end, !turn), cards[end] - getMaxDiff(cards, start, end-1, !turn));
	}
	else
	{
		if(cards[start] >= cards[end])
		{
			sum = (cards[start] - getMaxDiff(cards, start+1, end, !turn));
		}
		else
		{
			sum = cards[end] - getMaxDiff(cards, start, end-1, !turn);
		}
	}
	return dp[start][end] = sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll game = 1;
	while(true)
	{
		ll n, i;
		cin >> n;
		ll cards[n];
		if(n == 0) break;
		for(i = 0; i < n; i++)
		{
			cin >> cards[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << "In game " << game << ", the greedy strategy might lose by as many as " << getMaxDiff(cards, 0, n-1, 0) << " points.\n";
		game++;
	}
	return 0;
}
