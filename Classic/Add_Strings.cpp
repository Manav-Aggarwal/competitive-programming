/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

string add_zeros(string str, ll n)
{
	while(n--)
	{
		str += '0';
	}
	return str;
}
string add(string num1, string num2)
{
	string sum = "", a, b;
	ll i, summer, carry = 0;
	a = string(num1.rbegin(), num1.rend());
	b = string(num2.rbegin(), num2.rend());
	if(a.length() > b.length())
	{
		b = add_zeros(b, a.length()-b.length());
	}
	else
	{
		a = add_zeros(a, b.length() - a.length());
	}
	for(i = 0; i < min(a.length(), b.length()); i++)
	{
		summer = (ll)(a[i] + b[i] - 2*(ll)('0') + carry);
		carry = 0;
		if(summer > 9)
		{
			carry = summer/10;
			summer%= 10;
		}
		sum += (char)(summer + '0');
	}
	if(carry!=0)
	{
		sum += (char)(carry + '0');
	}
	return string(sum.rbegin(), sum.rend());
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << add("42000", "1");
	return 0;
}
