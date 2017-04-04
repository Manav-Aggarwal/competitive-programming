/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll lcs(ll agnes[], ll agnesLength, ll tom[], ll tomLength)
{
	ll LCS[agnesLength+1][tomLength+1], i, j;
	for(i = 0; i <= agnesLength; i++)
	{
		for(j = 0; j <= tomLength; j++)
		{
			if(i == 0 || j == 0)
			{
				LCS[i][j] = 0;
			}
			else if(agnes[i - 1] == tom[j - 1])
			{
				LCS[i][j] = LCS[i-1][j-1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
			
		}
	}
	return LCS[agnesLength][tomLength];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll d;
	cin >> d;
	while(d--)
	{
		ll num, a = 0, agnes[2222], agnesLength, e, maxL = 0;
		cin >> num;
		while(num)
		{
			agnes[a++] = num;
			cin >> num;
		}
		agnesLength = a;
		while(true)
		{
			cin >> num;
			if(num)
			{
				ll tom[2222];
				a = 0;
				while(num)
				{
					tom[a++] = num;
					cin >> num;
				}
				maxL = max(maxL, lcs(agnes, agnesLength, tom, a));
			}
			else
			{
				break;
			}
		}
		cout << maxL << endl;
	}
	return 0;
}
