/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 999999999
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, m, i;
	cin >> n >> m;
	ll arr[n];
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ll curr = 0, maxSum = -INF, prev = 0;
	for(i = 0; i < n; i++)
	{
		if(curr + arr[i] < m)
		{
			curr += arr[i];
		}
		else
		{
			curr += arr[i];
			while(curr > m)
			{
				curr -= arr[prev];
				prev++;
			}
		}
		if(curr <= m && maxSum < curr)
		{
			maxSum = curr;
		}
	}
	cout << maxSum << endl;
	return 0;
}
