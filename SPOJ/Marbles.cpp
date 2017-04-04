/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 1000000
ll binomialCoeff(ll n, ll k)
{
	if(k > n - k)
		k = n - k;
	ll i, ans = 1;
	for(i = 0; i < k; i++)
		ans = ans * (n-i)/(i+1);
	return ans;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		cout << binomialCoeff(n-1, k-1) << endl;
	}
	return 0;
}
