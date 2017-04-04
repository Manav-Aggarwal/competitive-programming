#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool isAnagram(string s, string s1)
{
	bool flag = true;
	if(s.length() == s1.length())
	{
		int alpha[26] ,alpha1[26];
		for(int i = 0; i < 26; i++)
		{
			alpha[i] = 0;
		}
		for(int i = 0; i < 26; i++)
		{
			alpha1[i] = 0;
		}
		for(int i = 0; i < s.length(); i++)
		{
			alpha[s[i]-'a']++;
		}
		for(int i = 0; i < s1.length(); i++)
		{
			alpha1[s1[i]-'a']++;
		}
		for(int i = 0; i < 26; i++)
		{
			if(alpha[i] != alpha1[i])
			{
				flag = false;
				break;
			}
		}
		return flag;
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
		string s, s1;
		cin >> s >> s1;
		if(isAnagram(s, s1))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
