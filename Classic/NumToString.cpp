/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

string numToString(ll num)
{
	ll i;
	string str = "";
	while(num != 0)
	{
		str += (char)( (num%10) + '0');
		num/=10;
	}
	str = string(str.rbegin(), str.rend());
	return str;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << numToString(1234);
	return 0;
}
