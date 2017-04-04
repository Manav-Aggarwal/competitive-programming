/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll binomialCoeff(ll n, ll k)
{
	ll ans = 1, i;
	if(k > n - k)
	{
		k = n-k;
	}
	
	for(i = 0; i < k; i++)
	{
		ans *= (n - i);
		ans /= (i+1);
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << binomialCoeff(5, 3);
	return 0;
}
