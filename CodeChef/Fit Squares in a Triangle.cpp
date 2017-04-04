#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[10001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int s = 0, f = 0, k = 1;
	dp[0] = 0; 
	for(int i = 1; i < 10001; i++)
	{
		dp[i] = s;
		if(f == 1)
		{
			f = 0;
			s+=k;
			k++;
		}
		else
		{
			f++;
		}
		
	}
	while(t--)
	{
		int n;
		cin >> n;
		cout << dp[n-1] << endl;
	}
	return 0;
}
