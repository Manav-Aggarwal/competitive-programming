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

pair<string, string> removeDups(string str1, string str2)
{
	ll i, j;
	for(i = 0; i < str1.length(); i++)
	{
		for(j = 0; j < str2.length(); j++)
		{
			if(str1[i] == str2[j])
			{
				str1.erase(str1.begin()+i);
				str2.erase(str2.begin()+j);

			}
		}
	}
	return make_pair(str1, str2);
}

ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, j, producti = 1, productj = 1, hcf;
	pair<string, string> temp;
	vector<ll> is, js;
	for(i = 10; i < 100; i++)
	{
		for(j = 10; j < i; j++)
		{
			if(i % 10 != 0 && j % 10 != 0) 
			{
				if(i == 65 && j == 26)
				{
					i = 65;
				}
				temp = removeDups(numToString(i), numToString(j) );
				ll num1 = stringToNum(temp.first), num2 = stringToNum(temp.second);
				if(num1 != i && num2 != j && (double) num1/num2 == (double)i/(double)j)
				{
					hcf = gcd(num1, num2);
					num1 /= hcf;
					num2 /= hcf;
					is.push_back(i); js.push_back(j);
				}
			}
		}
	}
	for(i = 0; i < is.size(); i++)
	{
		cout << js[i] << " / " << is[i] << endl ;
		producti *= is[i];
		productj *= js[i];
	}
	cout << "Product : " << productj << " / " << producti << endl;
	hcf = gcd(producti, productj);
	cout << "Lowest : " << productj/hcf << " / " << producti/hcf;
	return 0;
}
