#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
unsigned long long int dp[10000001][2];
unsigned long long int p[100001];
int main()
{	
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned long long int n , m, sum = 0, h;
	cin >> n >> m;
	for(unsigned long long int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 1; dp[1][1] = 1;
	for(unsigned long long int i = 2; i <= m; i++)
	{
		dp[i][0] = (i*dp[i-1][0] % m);
	}
	for(unsigned long long int i = 2; i <= m; i++)
	{
		dp[i][0] = (i*dp[i][0] % m);
		dp[i][1] = ((dp[i][0] + dp[i-1][1]) % m) % m;
	}
	for(unsigned long long int i = 1; i <= n; i++)
	{
		unsigned long long int d = p[i] % m;
		if(d&1)
		{
			unsigned long long int z = (d+1)/2;	
			if(p[i] >= m)
			{
				h = (dp[m][1] + (d*(((d*z) % m) % m) % m) % m) % m;
			}
			else 
			{
				h = (dp[d][1] + (d*(((d*z) % m) % m) % m) % m) % m;
			}
		}
		else
		{
			unsigned long long int z = d/2;	
			if(p[i] >= m)
			{
				h = (dp[m][1] + (d*(((z*(d+1))% m) % m) % m) % m) % m;
			}
			else 
			{
				h = (dp[d][1] + (d*(((z*(d+1)) % m) % m) % m) % m) % m;
			}
		}
	
		sum = (sum + h) % m; 
	}
	cout << sum;
	return 0;
}
