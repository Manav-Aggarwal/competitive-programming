#include <bits/stdc++.h>
#include <limits>
using namespace std;
#define endl '\n'
bool isPal(string s)
{
	int len2 = s.length()/2;
	for(int i = 0; i < len2; i++)
	{
		int v = (int) s[i];
		int v1 = (int) s[s.length()-i-1];
		if(v != v1)
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	int t;
	cin >> t;
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	while(t--)
	{
		string s;
		getline(cin, s);
		string str = "";
		for(int i = 0; i < s.length(); i++)
		{
			int v = (int) s[i];
			if((v >= 65 && v <= 90) || (v >= 97 && v <= 122) || (v >= 48 && v <= 57) || (v==32) )
			{
				str += s[i];
			}
		}
		if(isPal(str) == true)
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
