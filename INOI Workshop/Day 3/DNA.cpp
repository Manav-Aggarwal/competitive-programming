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
		ll n, i, j, k, mxL = 0;
		cin >> n;
		if(n == 0)
			break;
		string s1, s2;
		cin >> s1 >> s2;
		ll lcs[s1.length() + 1][s2.length() + 1], cont[s1.length()+1][s2.length()+1];
		cont[0][0] = 0;
		memset(cont, 0, sizeof(cont));
		for(i = 0; i <= s1.length(); i++)
		{
			for(j = 0; j <= s2.length(); j++)
			{
				if(i == 0 || j == 0)
				{
					lcs[i][j] = 0;
				}
				else
				{
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
					if(s1[i-1] == s2[j-1])
					{
						cont[i][j] = cont[i-1][j-1] + 1;
					}
					else
					{
						cont[i][j] = 0;
					}
					k = cont[i][j];
					if(cont[i][j] >= n)
					{
						for(k = n; k <= cont[i][j]; k++)
						{
							lcs[i][j] = max(lcs[i][j], lcs[i-k][j-k] + k);
						}
					}
				}
			}
		}
		cout << lcs[s1.length()][s2.length()] << endl;
	}
	return 0;
}
