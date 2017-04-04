#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		long long int n, minm = LONG_MAX;
		cin >> n;
		long long int horses[n];
		for(int i = 0; i < n; i++)
		{
			cin >> horses[i];
		}
		sort(horses, horses + n);
		for(int i = 1; i < n; i++)
		{
			minm = min(minm, abs(horses[i] - horses[i-1]));
		}
		cout << minm << endl;
	}
	return 0;
}
