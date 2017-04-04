/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isPandigital(ll num)
{
	set<ll> digits;
	while(num)
	{
		if(digits.count(num%10) == 1 || num % 10 == 0)
		{
			return true;
		}
		digits.insert(num%10);
		num /= 10;
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, num, maxNum = 0;
	for(i = 9234; i <= 9487; i++)
	{
		num = (i*100000) + (i * 2);
		if((!isPandigital(num)) && maxNum < num)
		{
			maxNum = num;
		}
	}
	cout << maxNum;
	return 0;
}
