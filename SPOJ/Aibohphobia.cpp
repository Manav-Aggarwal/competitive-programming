/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll lcs[6111][6111];
ll minChars(string s)
{
	ll i, j, len = s.length();
	for(i = 0; i <= s.length(); i++)
	{
		for(j = 0; j <= s.length(); j++)
		{
			lcs[i][j] = 0;
		}
	}
	string rev = string(s.rbegin(), s.rend());
	for(i = 0; i <= len; i++)
	{
		for(j = 0; j <= len; j++)
		{
			if(i == 0 || j == 0)
			{
				lcs[i][j] = 0;
			}
			else if(s[i-1] != rev[j-1])
			{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
			else
			{
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
		}
	}
	return len - lcs[len][len];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << minChars(s) << endl;
	}
	return 0;
}
