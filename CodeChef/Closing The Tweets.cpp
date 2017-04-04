#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s, in;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	long long n, k, index, i, count = 0;
	string str = "";
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		str+='0';
	}
	s = str;
	while(k--)
	{
		cin >> in;
		if(in == "CLICK")
		{
			cin >> index;
			index--;
			if(s[index] == '0')
			{
				count++;
				s[index] = '1';
			}
			else
			{
				count--;
				s[index] = '0';
			}
			cout << count << endl;
		}
		else
		{
			s = str;
			count = 0;
			cout << count << endl;
		}
	}
	return 0;
}
