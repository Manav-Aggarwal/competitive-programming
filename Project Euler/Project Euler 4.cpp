/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
bool isPalin(ll n)
{
	string s; ll i;
	ostringstream convert;
	convert << n;
	s = convert.str();
	for(i = 0; i < s.length()/2; i++)
	{
		if(s[i] != s[s.length()-i-1])
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, num = 0;
	for(i = 990; i >= 100; i-=11)
	{
		for(j = 999; j >= 100; j--)
		{
			if(i*j < num)
			{
				break;
			}
			if(isPalin(i*j))
			{
				num = max(num, i*j);
			}
		}
	}
	cout << num;
	return 0;
}
