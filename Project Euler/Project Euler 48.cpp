/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll mod = 1e10;
ll selfPower(ll num)
{
	ll i = num, product = 1;
	while(i--)
	{
		product*= num;
		product %= mod;
	}
	return product;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, sum = 0;
	for(i = 1; i <= 1000; i++)
	{
		sum += selfPower(i);
		sum %= mod;
	}
	cout << sum;
	return 0;
}
