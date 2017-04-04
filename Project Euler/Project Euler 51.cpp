/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 1000000;
ll arr[1000001];
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(M); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j <= M; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
}
bool containsThreeDups(ll num) // not considering last digit
{
	ll arr[10], i;
	num/=10;
	for(i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	while(num)
	{
		arr[num%10]++;
		num/=10;
	}
	for(i = 0; i < 10; i++)
	{
		if(arr[i] >= 3)
		{
			return true;
		}
	}
	return false;
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
bool isTrue(string num)
{
	ll h, i, j, count = 0, k;
	for(i = 0; i < num.length() - 3; i++)
	{
		for(j = i + 1; j < num.length() - 2; j++)
		{
			for(h = j + 1; h < num.length() - 1; h++)
			{
				if(num[i] == num[j] && num[j] == num[h] )
				{
					for(k = 0; k < 10; k++)
					{
						num[i] = num[j] = num[h] = k + '0';
						if(num[0] != '0' && arr[stringToNum(num)])
						{
							count++;
						}
					}
					if(count >= 8)
					{
						return true;
					}
					return false;
				}
			}
		
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i;
	for(i = 100001; i < 1000000; i+=2)
	{
		if(arr[i] && containsThreeDups(i) && isTrue(numToString(i)))
		{
			cout << i << " ";
		}
	}
	return 0;
}
