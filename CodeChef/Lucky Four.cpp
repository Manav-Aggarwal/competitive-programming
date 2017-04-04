#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		string s;
		long long int count = 0;
		cin >> s;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '4')
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
