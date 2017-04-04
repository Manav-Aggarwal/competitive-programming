/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

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
	string pandigitals = "1023456789";
	ll primes[] = {2, 3, 5, 7, 11, 13, 17}, i;
	vector<string> nums;
	bool satisfies;
	while(next_permutation(pandigitals.begin(), pandigitals.end()))
	{
		satisfies = true;
		for(i = 0; i < 7; i++)
		{
			if(stringToNum(pandigitals.substr(i + 1, 3)) % primes[i])
			{
				satisfies = false;
				break;
			}
		}
		if(satisfies)
		{
			nums.push_back(pandigitals);
		}
	}
	for(i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	return 0;
}
