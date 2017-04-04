/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll StringToNumValue(string s)
{
	ll sum = 0, i;
	for(i = 0; i < s.length(); i++)
	{
		sum += s[i] - 'A' + 1;
	}
	return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream names("names.txt");
	stringstream buffer;
	buffer << names.rdbuf();
	string test = buffer.str();
	test.erase(remove(test.begin(), test.end(), '"'), test.end());
	vector<string> arr;
	string temp = "";
	ll i, sum = 0;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == ',')
		{
			arr.push_back(temp);
			temp = "";
		}
		else
		{
			temp += test[i];
		}
	}
	arr.push_back(temp);
	sort(arr.begin(), arr.end());
	for(i = 0; i < arr.size(); i++)
	{
		sum += StringToNumValue(arr[i]) * (i+1);
	}
	cout << sum;
	return 0;
}
