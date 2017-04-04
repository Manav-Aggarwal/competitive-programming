/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 9999999
ll dp[1111];
ll recur(ll n, ll m, ll count)
{
	if(n <= 0)
	{
		return INF;
	}
	if(n == m)
		return count;
	else
	{
		if(m % 2 == 0)
		{
			if(n - m/2 < n*2 - m)
				return recur(n-1, m, count+1);
			else
				return recur(n, m/2, count+1);
		}
		else
			return recur(n, m+1, count+1);
	}
}
int main() 
{
 
    ll n, m;
    cin >> n >> m;
    cout << recur(n, m, 0) << endl;
    return 0;
}
