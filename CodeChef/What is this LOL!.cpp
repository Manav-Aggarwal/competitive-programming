#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool canBePal(string s)
{
		int alpha[26];
		int odd = 0;
		for(int i = 0; i < 26; i++)
		{
			alpha[i] = 0;
		}
		for(int i = 0; i < s.length(); i++)
		{
			alpha[s[i]-'a']++;
		}
		for(int i = 0; i < 26; i++)
		{
			if(alpha[i] == 0)
			{
				continue;
			}
			else if(alpha[i] & 1)
			{
				odd++;
			}
		}
		if(odd > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if(!(canBePal(s)))
		{
			cout << "Not Possible" << endl;
		}
		else
		{
			
		}
	}
	return 0;
}
