/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll binomialCoeff(ll n, ll k)
{
	ll i, j, count = 0;
	ll C[n+1][k+1];
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= min(i, k); j++)
		{
			if(j == 0 || j == i)
			{
				C[i][j] = 1;
			}
			else
			{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				if(C[i][j] > 1000000)
				{
					C[i][j] = 1000000;
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, j, count = 0;
	cout << binomialCoeff(100, 100);
	return 0;
}
