/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 999999;
bool arr[1000000], checked[1000000];
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
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll a, b, c, d, e, f, num, i, j, k, l, m, n;
	bool isPrime;
	string stringNum, temp;
	vector<ll> isCircular, tempCircular; 
	ll digits[] = {0, 1, 3, 7, 9};
	for(a = 0; a < 5; a++)
	{
		for(b = 0; b < 5; b++)
		{
			if(b == 0 && a != 0)
			{
				continue;
			}
			for(c = 0; c < 5; c++)
			{
				if(c == 0 && a != 0 && b != 0)
				{
					continue;
				}
				for(d = 1; d < 5; d++)
				{
					for(e = 1; e < 5; e++)
					{
						for(f = 1; f < 5; f++)
						{
							num = digits[a]*100000 + digits[b]*10000 + digits[c]*1000 + digits[d]*100 + digits[e]*10 + digits[f];
							if(checked[num])
							{
								continue;
							}
							isPrime = true;
							stringNum = numToString(num);
							tempCircular.clear();
							temp = stringNum;
							temp += stringNum;
							for(i = 0; i < stringNum.length(); i++)
							{
								checked[stringToNum(temp.substr(i, stringNum.length()))] = true;
								if(arr[stringToNum(temp.substr(i, stringNum.length()))] == 0)
								{
									isPrime = false;
								}
								tempCircular.push_back(stringToNum(temp.substr(i, stringNum.length())));
							} 
							if(isPrime)
							{
								for(i = 0; i < tempCircular.size(); i++)
								{
									isCircular.push_back(tempCircular[i]);
								}
							}
						}
					}
				}
			}
		}
	}
	for(i = 0; i < isCircular.size(); i++)
	{
		cout << isCircular[i] << endl;
	}
	cout << "Size : " << isCircular.size() + 13; //Including those below 100
	return 0;
}
