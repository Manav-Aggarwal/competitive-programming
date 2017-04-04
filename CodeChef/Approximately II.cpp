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
		long long int n, k, cnt = 0, min = INT_MAX, i , j, val;
		cin >> n >> k;
		long long int a[n];
		for(i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for(i = 0; i < n-1; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				val = abs(a[i] + a[j] - k);
				if(min > val)
				{
					min = val;
					cnt = 1;
				}
				else if(val == min)
				{
					cnt++;
				}
			}
		}
		cout << min << " " << cnt << endl;
	}
	return 0;
}
