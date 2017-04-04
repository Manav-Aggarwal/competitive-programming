/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 1111
vector<ll> nums;
void init()
{
	nums.push_back(0);
	nums.push_back(1);
	ll i = 2, j = 1, k, sz = 2;
	while(sz <= MAXN)
	{
		for(k = 0; k < j; k++)
		{
			nums.push_back(i);
			sz++;
		}
		i++; j++;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		cout << nums[n] << endl;
	}
	return 0;
}
