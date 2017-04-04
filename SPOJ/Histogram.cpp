/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll int
ll n, arr[16], dp[1 << 16][16], cnt[1 << 16][16];
ll solve(ll mask, ll last)
{
	ll i, tmp, ans = 0;
	if(mask == (1 << n) - 1)
	{
		cnt[mask][last] = 1;
		return arr[last];
	}
	else if(dp[mask][last] != -1)
		return dp[mask][last];
	else
	{
		dp[mask][last] = 0;
		for(i = 0; i < n; i++)
		{
			if(!(mask & (1 << i)))
			{
				tmp = solve(mask | (1 << i), i) + abs(arr[last] - arr[i]);
				if(tmp > ans)
				{
					ans = tmp;
					cnt[mask][last] = 0;
				}
				if(tmp == ans) cnt[mask][last] += cnt[mask | (1 << i)][i];
			}
		}
		return dp[mask][last] = ans;
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		cin >> n;
		if(n == 0)
			break;
		memset(dp, -1, sizeof(dp));
		for(ll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		ll perim = 2*n, cont = 0, ans = 0, curr, i;
		for(i = 0; i < n; i++)
		{
			curr = solve((1 << i), i) + arr[i];
			if(curr > ans)
			{
				ans = curr;
				cont = 0;
			}
			if(curr == ans) cont += cnt[1 << i][i];
		}
		cout << perim + ans << " " << cont << endl;
	}
	return 0;
}
