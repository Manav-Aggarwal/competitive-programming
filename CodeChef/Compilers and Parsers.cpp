#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s;
long long int l = 0, i, oc, mx;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		l = oc = mx =0;
		for(i = 0; i < s.length(); i++)
		{
			if(s[i] == '<')
			{
				oc++;
			}
			else if(s[i] == '>')
			{
				oc--; l++;
				if(oc == 0)
				{
					mx = max(mx, i + 1);
				}
				else if(oc < 0)
				{
					break;
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}
