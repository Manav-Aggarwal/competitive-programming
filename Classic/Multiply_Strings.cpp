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
string multiply(string num1, string num2)
{
	string product, a, b;
	ll i, j, holder, carry;
	vector<string> toAdd;
	a = string(num1.rbegin(), num1.rend());
	b = string(num2.rbegin(), num2.rend());
	for(i = 0; i < a.length(); i++)
	{
		carry = 0;
		product = "";
		for(j = 0; j < b.length(); j++)
		{
			holder = ((ll)(a[i] - '0') * (ll)(b[j] - '0') ) + carry;
			carry = 0;
			if(holder > 9)
			{
				carry = holder/10;
				holder%=10;
			}
			product += (char)(holder+'0');
		}
		if(carry!=0)
		{
			product += (char)(carry+'0');
		}
		toAdd.push_back(string(product.rbegin(), product.rend()));
	}
	product = toAdd[0];
	for(i = 1; i < toAdd.size(); i++)
	{
		product = add(product, add_zeros(toAdd[i], i));
	}
	return product;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << multiply("1084483", "12");
	return 0;
}
