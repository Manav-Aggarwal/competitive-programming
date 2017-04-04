/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll SumOfSquaresTillN(ll n)
{
	return ( n * (n+1) * ((2*n) + 1) )/ 6;
}
ll SumOfNumsTillN(ll n)
{
	return (n * (n+1))/2;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;
	cout << (SumOfNumsTillN(n) * SumOfNumsTillN(n) - SumOfSquaresTillN(n));
	return 0;
}
