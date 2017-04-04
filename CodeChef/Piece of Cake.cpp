#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int flag = 0, i, len = s.length();
		int alpha[26];
		for(i = 0; i < 26; i++)
		{
			alpha[i] = 0;
		}
		for(i = 0; i < len; i++)
		{
			alpha[s[i] - 'a']++;
		}
		for(i = 0; i < 26; i++)
		{
			if(alpha[i] == len-alpha[i])
			{
				flag = 1;
				break;
			}
		}
		cout << ((flag) ? "YES" : "NO");
		cout << endl;
	}
	return 0;
}
