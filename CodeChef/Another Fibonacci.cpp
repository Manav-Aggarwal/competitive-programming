/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
ll mod = 99991;
ll fib(ll n)
{
  
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k, i, sum;
	cin >> n >> k;
	ll arr[n+1];
	arr[0] = 0;
	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for(i = 1; i <= n; i++)
	{
		arr[i] = arr[i] + arr[i-1];
	}
	sum = 0;
	for(i = k; i <= n; i++)
	{
		sum = (sum + fib(arr[i] - arr[i-k])) % mod;
	}
	cout << sum % mod;
	return 0;
}
