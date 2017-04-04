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
		long long int val = 0, i;
		string s;
		cin >> s;
		for(i = 0; i < s.length(); i++)
		{
			val += (int)(s[i]);
		}
		val /= s.length();
		cout << (char)(val) << endl;
	}
	return 0;
}
