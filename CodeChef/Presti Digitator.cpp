#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
unsigned long long int dp[21];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	dp[1] = 0; dp[2] = 1;
	for(int i = 3; i < 21; i++)
	{
		dp[i] = (i-1) * (dp[i-2] + dp[i-1]);
	}
	while(t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
