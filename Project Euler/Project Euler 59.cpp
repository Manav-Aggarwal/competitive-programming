/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll stringToNum(string num)
{
	ll i, number = 0;
	for(i = 0; i < num.length(); i++)
	{
		number += num[i] - '0';
		number *= 10;
	}
	return number/10;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, j, k, l, spaceVal = (ll)(' '), tmp, count, maxCount = 0, sum = 0;
	ifstream cipher("cipher.txt");
	stringstream buffer;
	buffer << cipher.rdbuf();
	string test, temp = "", tryKey, key;
	test = buffer.str();
	test.erase(remove(test.begin(), test.end(), '\n'), test.end());
	vector<ll> chars;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == ',')
		{
			chars.push_back(stringToNum(temp));
			temp = "";
		}
		else
		{
			temp += test[i];
		}
	}
	chars.push_back(stringToNum(temp));
	for(i = 0; i < 26; i++)
	{
		for(k = 0; k < 26; k++)
		{
			for(l = 0; l < 26; l++)
			{
				
				tryKey += ((ll)(i + 'a'));
				tryKey += ((ll)(k + 'a'));
				tryKey += ((ll)(l + 'a'));
				count = 0;
				for(j = 0; j < chars.size(); j++)
				{
					tmp = chars[j] ^ tryKey[j%3];
					if(tmp == spaceVal)
					{
						count++;
					}
					if(count > maxCount)
					{
						maxCount = count;
						key = tryKey;
					}
				}
				tryKey = "";
			}
		}
	}
	for(j = 0; j < chars.size(); j++)
	{
		tmp = chars[j] ^ key[j%3];
		cout << (char)(tmp);
	}
	for(j = 0; j < chars.size(); j++)
	{
		tmp = chars[j] ^ key[j%3];
		sum += tmp;
	}
	cout << endl << endl << sum;
	return 0;
}
