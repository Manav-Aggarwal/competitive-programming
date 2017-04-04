#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
unsigned long long int dp[101];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	dp[0] = 1;
	for(long long int i = 1; i <= 100; i++)
	{
		dp[i] = i*dp[i-1];
	}
	while(T--)
	{
		long long int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
