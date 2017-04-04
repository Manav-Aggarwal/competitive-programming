#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		char out, s[400];
		gets(s);
		int alpha[26], i, flag = 0;
		for(i = 0; i < strlen(s); i++)
		{
			if((s[i] - 'a' >= 0 && s[i] - 'a' <= 25 ) || (s[i] - 'A' >= 0 && s[i] - 'A' <= 25))
			{
				if(s[i] < (int)'a')
				{
					s[i] = char((int)s[i] + int(' '));
				}
				alpha[s[i] - 'a'] = 0;
			}
		}
		for(i = 0; i < 26; i++)
		{
			if(alpha[i] != 0)
			{
				flag = 1;
				cout << char(i + 'a') << char(10);
				break;
			}
		}
		if(flag == 0)
		{
			cout << '~' << char(10);
		}
	}
	return 0;
}
