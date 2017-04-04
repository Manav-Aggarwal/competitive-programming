#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string h;
bool is_palin(string s)
{
	for(long i = 0; i < s.length(); i++)
	{
		if(s[i] != s[s.length()-i-1])
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> h;
		if(is_palin(h))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
	return 0;
}
