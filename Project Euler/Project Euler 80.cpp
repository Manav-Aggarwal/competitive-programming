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
string remove_zeros(string n)
{
	ll pos = n.length()-1, i;
	string temp = "";
	while(pos >= 0 && n[pos] == '0')
	{
		pos--;
	}
	for(i = 0; i <= pos; i++)
	{
		temp += n[i];
	}
	return temp;
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
	diff = remove_zeros(diff);
	return string(diff.rbegin(), diff.rend());
}
ll stringToNum(string str)
{
	ll i, num = 0;
	for(i = 0; i < str.length(); i++)
	{
		num += (ll)str[i] - '0';
		num*= 10;
	}
	return num/10;
}
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
bool isGreaterThan(string num1, string num2)
{
	if(num1.length() > num2.length())
	{
		return true;
	}
	else if(num2.length() > num1.length())
	{
		return false;
	}
	return num1 > num2;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("output.out", "w", stdout);
	string num, digits, tmp, diff, prod;
	ll i = 1, j, sum = 0, counter;
	for(counter = 2; counter < 100; counter++)
	{
		if((ll)sqrt(counter)*(ll)sqrt(counter) == counter)
		{
			continue;
		}
		num = numToString(counter);
		digits = "";
		i = 1;
		bool didNotBreak;
		while(i*i < stringToNum(num))
		{
			i++;
		}
		i--;
		num = subtract(num, numToString(i*i));
		digits += (char)(i+'0');
		while(digits.length() < 100)
		{
			num = add_zeros(num, 2);
			tmp = multiply(digits, "20");
			didNotBreak = true;
			for(j = 1; j < 10; j++)
			{
				tmp[tmp.length()-1] = (char)(j + '0');
				prod = multiply(tmp, numToString(tmp[tmp.length()-1] - '0'));
				if(isGreaterThan(prod, num))
				{
					didNotBreak = false;
					break;
				}
			}
			j--;
			if(!didNotBreak)
			{
				tmp[tmp.length()-1] = (char)(j + '0');
				prod = multiply(tmp, numToString(tmp[tmp.length()-1] - '0'));
			}
			digits += (char)(j + '0');
			num = subtract(num, prod);
		}
		for(i = 0; i < digits.length(); i++)
		{
			sum += digits[i] - '0';
		}
	}
	cout << sum;
	return 0;
}
