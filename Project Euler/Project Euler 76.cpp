/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
// Alternative soln : Problem 31.
ll partitions(ll n, ll k)
{
	ll i, j;
	ll partitionTable[n+1][k+1];
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= k; j++)
		{
			if(j == 0 )
			{
				partitionTable[i][j] = 0;
			}
			else if(i == 0)
			{
				partitionTable[i][j] = 1;
			}
			else if(j > i)
			{
				partitionTable[i][j] = partitionTable[i][j-1];
			}
			else
			{
				partitionTable[i][j] = partitionTable[i][j-1] + partitionTable[i - j][j];
			}
		}
	}
	return partitionTable[n][k];
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cout << "Which number do you want to partition bro? ";
	ll n; 
	cin >> n;
	cout << n << " has " << partitions(n, n-1) << " partitions.";
	return 0;
}
