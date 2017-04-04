/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j;
	cin >> n;
	string line, temp = "";
	set<string> words;
	cin.ignore();
	for(i = 0; i < n; i++)
	{
		getline(cin, line);
		for(j = 0; j < line.length(); j++)
		{
			if(isalpha(line[j]))
			{
				line[j] = tolower(line[j]);
				temp += line[j];
			}
			else if(line[j] == ' ' && temp.length() > 0)
			{
				words.insert(temp);
				temp = "";
			}
		}
		if(temp.length() > 0)
		{
			words.insert(temp);
		}
		temp = "";
	}
	cout << words.size() << endl;
	for(set<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
