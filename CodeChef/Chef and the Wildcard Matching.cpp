/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		string x, y;
		cin >> x >> y;
		bool canBe = true;
		for(int i = 0; i < x.length(); i++)
		{
			if(x[i] != y[i] && x[i] != '?' && y[i] != '?')
			{
				canBe = false;
				break;
			}
		}
		if(canBe)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
