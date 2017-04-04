/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i;
	cin >> n;
	ll arr[n];
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	bool flg = true;
	for(i = n-1; i >= 0; i--)
	{
		arr[i] -= i;
		if(arr[i] < 0)
		{
			flg = false;
		}
	}
	if(flg)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
