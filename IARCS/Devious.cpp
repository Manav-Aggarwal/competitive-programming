/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool wayToSort(pair<ll, ll> a, pair<ll, ll> b){return a.first < b.first;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll n, i, summer = 0, min = INT_MAX, min_start = 0, min_end = 0, holder;
	bool decide;
	cin >> n;
	ll arr[n];
	pair<ll, ll> sum[n];
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
		summer += arr[i];
		sum[i] = make_pair(summer, i+1);
	}
	sort(sum, sum + n, wayToSort);
	for(i = 0; i < n-1; i++)
	{
		holder = sum[i].first - sum[i+1].first;
		if((abs(holder) < abs(min)) || (abs(holder) == abs(min) && abs(sum[i].second - sum[i+1].second) >= abs(min_end - min_start)))
		{
			decide = sum[i].second < sum[i+1].second;
			min_start = sum[i].second;
			min_end = sum[i+1].second;
			min = decide ? -holder : holder;
		}
	}
	if(min_end < min_start)
	{
		min_end -= min_start;
		min_start += min_end;
		min_end = -(min_end) + min_start; 
	}
	cout << min << endl << min_start + 1 << " " << min_end;
	return 0;
}
