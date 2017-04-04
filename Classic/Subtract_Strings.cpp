/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii make_pair

string add_zeros(string str, ll n)
{
	while(n--)
	{
		str += '0';
	}
	return str;
}
string subtract(string num1, string num2)
{
	string a, b, diff = "";
	ll i, holder, carry;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if(num1.length() > num2.length())
	{
		num2 = add_zeros(num2, num1.length()-num2.length());
	}
	else
	{
		num1 = add_zeros(num1, num2.length() - num1.length());
	}
	carry = 0;
	for(i = 0; i < num1.length(); i++)
	{
		holder = (ll)(num1[i] - num2[i] + carry);
		carry = 0;
		if(holder < 0)
		{
			holder += 10;
			carry = -1;
		}
		diff += (char)(holder + '0');
	}
	return string(diff.rbegin(), diff.rend());
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << subtract("123", "22");
	return 0;
}
