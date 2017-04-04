/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll budget, parties, i, j, fee, funSum;
	cin >> budget >> parties;
	while(!(budget == 0 && parties == 0))
	{
		ll entranceFee[parties], fun[parties];
		for(i = 0; i < parties; i++)
		{
			cin >> entranceFee[i] >> fun[i];
		}
		ll funAtParties[parties+1][budget+1];
		for(i = 0; i <= parties; i++)
		{
			for(j = 0; j <= budget; j++)
			{
				if(i == 0 || j == 0)
				{
					funAtParties[i][j] = 0;
				}
				else if(entranceFee[i-1] > j)
				{
					funAtParties[i][j] = funAtParties[i-1][j];
				}
				else
				{
					funAtParties[i][j] = max(funAtParties[i-1][j], fun[i-1] + funAtParties[i-1][j - entranceFee[i-1]]);
				}
			}
		}
		fee = budget-1, funSum = funAtParties[parties][budget];
		while(funAtParties[parties][fee] == funSum)
		{
			fee--;
		}
		cout << fee + 1 << " " << funSum << endl;
		cin >> budget >> parties;
	}
	return 0;
}
