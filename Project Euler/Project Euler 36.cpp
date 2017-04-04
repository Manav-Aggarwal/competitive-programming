/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll isPalin(ll num, ll base)
{
	ll reversed = 0;
	ll n = num;
	while(n)
	{
		reversed = base*reversed + n % base;
		n /= base;
	}
	return num == reversed; 
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, sum = 0;
	vector<ll> palins;
	for(i = 1; i < 1000000; i+=2)
	{
		if(isPalin(i, 10) && isPalin(i, 2))
		{
			palins.push_back(i);
		}
	}
	for(i = 0; i < palins.size(); i++)
	{
		cout << palins[i] << endl;
		sum += palins[i];
	}
	cout << "Sum : " << sum;
	return 0;
}
