/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll power10(ll k)
{
	ll p = 1;
	while(k--)
	{
		p*= 10;
	}
	return p;
}
ll reversednum(ll n)
{
	ll num = 0;
	ll len = log10(n)+1;
	ll dup = len - 1;
	while(len--)
	{
		ll e = n % 10;
		ll k = power10(dup);
		num = e*k + num;
		n/=10; dup--;
	}
	return num;
}
bool isPal(ll n)
{
	string s;
	ostringstream convert;
	convert << n;
	s = convert.str();
	if(s == string(s.rbegin(), s.rend()))
	{
		return true;
	}
	return false;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, sum, step = 0, count = 0;
	for(i = 100; i < 10000; i++)
	{
		sum = i;
		for(step = 0; step < 50; step++)
		{
			sum = sum + reversednum(sum);
			step++;
			if(isPal(sum))
			{
				break;
			}
		}
		if(step == 50)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
