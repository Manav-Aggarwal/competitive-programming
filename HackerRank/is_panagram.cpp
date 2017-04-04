#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("test.in", "r", stdin);
	set<char> alpha;
	string str;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++)
	{
		int tmp = tolower(str[i]);
		if(tmp >= 'a' && tmp <= 'z')
		{
			alpha.insert(tmp);
		}
	}
	cout << ((alpha.size() == 26) ? "pangram" : "not pangram");
	return 0;
}
