#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int weights[12], costs[12];
long long int m, n, k, i, t;
long long int getmaxweight(long long int n, long long int k)
{
	if(n == 0)
	{
		return 0;
	}
	if(k <= 0)
	{
		return 0;
	}
	else
	{
		if(k >= costs[n])
		{
			return max(weights[n] + getmaxweight(n-1, k-costs[n]), getmaxweight(n-1, k));
		}
		else
		{
			return getmaxweight(n-1, k);
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(i = 1; i <= n; i++)
		{
			cin >> costs[i] >> weights[i];
		}
		cout << getmaxweight(n, k) << endl;
	}
	return 0;
}
