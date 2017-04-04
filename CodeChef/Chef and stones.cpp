#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long int n, k, mx = 0;
		cin >> n >> k;
		long long int time[n], profit[n];
		for(long long int i = 0; i < n; i++)
		{
			cin >> time[i];
		}
		for(long long int i = 0; i < n; i++)
		{
			cin >> profit[i];
		}
		for(long long int i = 0; i < n; i++)
		{
			long long int d = (k/time[i]) * profit[i];
			mx = max(mx, d);
		}
		cout << mx << endl;
	}
	return 0;
}
