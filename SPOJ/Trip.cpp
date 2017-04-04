/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

map<string, bool> isPresent;
string alice, bob;
vector<string> css;
ll maxLength;
void getCS(string cs, ll aliceS, ll bobS)
{
	if(aliceS >= alice.length() || bobS >= bob.length())
	{
		if(cs.length() == maxLength && !isPresent[cs])
		{
			isPresent[cs] = true;
			css.push_back(cs);
		}
		return;
	}
	if(isPresent[cs])
	{
		return;
	}
	if(alice[aliceS] == bob[bobS])
	{
		cs += alice[aliceS];
		getCS(cs, aliceS+1, bobS+1);
	}
	else
	{
		getCS(cs, aliceS+1, bobS);
		getCS(cs, aliceS, bobS+1);
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		isPresent.clear(); css.clear();
		cin >> alice >> bob;
		ll i, j, lcs[alice.length()+1][bob.length()+1];
		for(i = 0; i <= alice.length(); i++)
		{
			for(j = 0; j <= bob.length(); j++)
			{
				if(i == 0 || j == 0)
				{
					lcs[i][j] = 0;
				}
				else if(alice[i-1] == bob[j-1])
				{
					lcs[i][j] = 1 + lcs[i-1][j-1];
				}
				else
				{
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				}
			}
		}
		maxLength = lcs[alice.length()][bob.length()];
		getCS("", 0, 0);
		sort(css.begin(), css.end());
		for(i = 0; i < css.size(); i++)
		{
			cout << css[i] << endl;
		}
		if(css.size() == 0)
		{
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
