/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll greatest[] = {9, 98, 987, 9876, 98765, 987654, 9876543, 98765432, 987654321};
ll smallest[] = {1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 0};

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

bool isRepFree(string str)
{
	ll i;
	map<char, bool> visited;
	for(i = 0; i < str.length(); i++)
	{
		if(visited[str[i]] || str[i] == '0')
		{
			return false;
		}
		else
		{
			visited[str[i]] = true;	
		}
	}
	return true;
}
string nextRepFree(string num)
{
	ll len = num.length(), i, j;
	string newNum;
	for(i = 0; i < len; i++)
	{
		if(num[i] == '0')
		{
			for(ll k = i; k < len; k++)
			{
				num[k] = '1';
			}
		}
	}
	while(!isRepFree(num))
	{
		for(i = len-1; i > 0; i--)
		{
			for(j = i-1; j >= 0; j--)
			{
				if(num[i] == '0')
				{
					for(ll k = i; k < len; k++)
					{
						num[k] = '1';
					}
				}
				if(num[j] == '0')
				{
					for(ll k = j; k < len; k++)
					{
						num[k] = '1';
					}
				}
				if(num[i] == num[j])
				{
					if(num[i] != '9')
					{
						num[i] = (char)((int)(num[i]) + 1);
					}
					else
					{
						newNum = add_zeros("1", len - i - 1);
						num = add(num, newNum);	
					}
				}
			}
		}
	}
	return num;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i;
	cin >> n;
	if(n <= 0)
	{
		cout << 1;
	}
	else if(n >= greatest[numToString(n).length()-1])
	{
		cout << smallest[numToString(n).length()];
	}
	else
	{
		string num = numToString(n);
		for(i = 0; i < num.length(); i++)
		{
			if(num[i] == '0')
			{
				for(ll j = i; j < num.length(); j++)
				{
					num[j] = '1';
				}
				if(isRepFree(num))
				{
					cout << num;
					return 0;
				}
			}
		}
		n++;
		num = numToString(n);
		cout << nextRepFree(num);
	}
	return 0;
}
