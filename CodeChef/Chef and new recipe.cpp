/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, i;
	cin >> t;
	while(t--)
	{
		ll n, minNum = INT_MAX, sum = 0;
		bool hasLessThanTwo = false;
		cin >> n;
		ll arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
			if(arr[i] < 2)
			{
				hasLessThanTwo = true;
			}
			minNum = min(minNum, arr[i]);
			sum += arr[i];
		}
		if(hasLessThanTwo)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << sum - minNum + 2 << endl;
		}	
	}
	return 0;
}
