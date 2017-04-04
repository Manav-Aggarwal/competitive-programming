/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		string encoded;
		cin >> encoded;
		if(encoded == "0")
		{
			break;
		}
		ll dp[encoded.length()], i, num;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i = 1; i < encoded.length(); i++)
		{
			num = (encoded[i-1]-'0')*10 + (encoded[i]-'0');
			if(encoded[i] != '0')
			{
				dp[i] = dp[i-1];
			}
			if(num <= 26 && num > 9)
			{
				if(i > 1)
					dp[i] += dp[i-2];
				else
					dp[i]++;
			}
		}
		cout << dp[encoded.length()-1] << endl;
	}
	return 0;
}
