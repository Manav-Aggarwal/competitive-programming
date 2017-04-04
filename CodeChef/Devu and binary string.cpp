/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
char change(char c)
{
	return (c == '0') ? '1' : '0';
}
ll countInvs(string s, string s1)
{
	ll count = 0, i;
	for(i = 0; i < s.length(); i++)
	{
		if(s[i] != s1[i])
		{
			count++;
		}
	}
	return count;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t, n, k, i, count, j;
	string s, temp;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		if(k > 1)
		{
			vector<string> subs;
			count = 0; temp = "";
			temp += s[0];
			for(i = 1; i < s.length(); i++)
			{	
				if(s[i] == temp[0])
				{
					temp += s[i];
				}
				else
				{
					subs.push_back(temp);
					temp = "";
					temp+= s[i];
				}
			}
			subs.push_back(temp);
			for(i = 0; i < subs.size(); i++)
			{
				if(subs[i].length() > k)
				{
					if(subs[i].length() % (k + 1))
					{
						j = k;
						while(j < subs[i].length() )
						{
							subs[i][j] = change(subs[i][j]);
							j += k + 1; 
							count++;
						}
					}
					else
					{
						j = subs[i].length() - 2;
						while(j >= 0)
						{
							subs[i][j] = change(subs[i][j]);
							j -= k + 1;
							count++;
						}
					}
				}
			}
			temp = "";
			for(i = 0; i < subs.size(); i++)
			{
				temp += subs[i];
			}
			cout << count << endl << temp << endl;
		}
		else
		{
			string c0 = "0", c1 = "1";
			for(i = 1; i < s.length(); i++)
			{
				c0 += change(c0[i-1]);
				c1 += change(c1[i-1]);
			}
			ll invs0 = countInvs(s, c0), invs1 = countInvs(s, c1);
			if(invs0 < invs1)
			{
				cout << invs0 << endl << c0 << endl;
			}
			else
			{
				cout << invs1 << endl << c1 << endl;
			}
		}
	}
	return 0;
}
