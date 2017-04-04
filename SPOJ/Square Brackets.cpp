/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll d;
	cin >> d;
	while(d--)
	{
		ll n, k, i, j;
		cin >> n >> k;
		bool s[2*n + 1];
		memset(s, false, sizeof(s));
		for(i = 0; i < k; i++)
		{
			cin >> j;
			s[j] = true;
		}
		ll cnt[50][50];
		cnt[1][0] = 0; cnt[1][1] = 1;
		for(i = 2; i <= 2*n; i++)
		{
			cnt[1][i] = 0;
		}
		for(i = 2; i <= 2*n; i++)
		{
			for(j = 0; j <= i; j++)
			{
				if(s[i])
				{
					cnt[i][j] = ((j == 0) ? 0 : cnt[i-1][j-1]);
				}
				else
				{
					cnt[i][j] = cnt[i-1][j+1] + ((j==0) ? 0: cnt[i-1][j-1]);
				}
			}
		}
		cout << cnt[2*n][0] << endl;
	}
	return 0;
}
