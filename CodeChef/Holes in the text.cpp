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
		int holes = 0;
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == 'A' || s[i] == 'D' || s[i] == 'O' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R')
			{
				holes += 1;
			}
			else if(s[i] == 'B')
			{
				holes += 2;
			}
			
		}
		cout << holes << endl;
	}
	return 0;
}
