/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 9999999999
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll at, bt, i, curr = 0, minSum = INF, maxI = 0, prev, st;
		cin >> at >> bt;
		ll arr[at];
		for(i = 0; i < at; i++)
		{
			cin >> arr[i];
		}
		prev = 0; st = 0;
		for(i = 0; i < at; i++)
		{
			if(bt >= curr + arr[i])
			{
				curr += arr[i];
				st++;
			}
			else
			{
				curr += arr[i];
				st++;
				while(curr > bt)
				{
					curr -= arr[prev];
					prev++; st--;
				}
			}
			if(maxI < st)
			{
				maxI = st;
				minSum = curr;
			}
			else if(maxI == st)
			{
				minSum = min(minSum, curr);
			}
		}
		cout << minSum << " " << maxI << endl;
	}
	return 0;
}
