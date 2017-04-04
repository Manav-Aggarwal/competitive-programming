#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int arr[100001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, k, mx = INT_MIN, i, mx2 = INT_MIN;
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	if(k == 0)
	{
		for(i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			arr[i] = mx - arr[i];
			mx2 = max(mx2, arr[i]);
		}
		if(k%2)
		{
			for(i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
		}
		else
		{
			for(i = 0; i < n; i++)
			{
				arr[i] = mx2 - arr[i];
			}
			for(i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
		}
	}
	
	return 0;
}
