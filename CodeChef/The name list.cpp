#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	map<string, long long> dict;
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		dict[s]++;
	}
	for(map<string, long long> :: iterator it = dict.begin(); it != dict.end(); it++)
	{
		cout << it -> first << " " << it -> second << endl;
	}
	return 0;
}
