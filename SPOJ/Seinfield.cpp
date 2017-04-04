/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll iter = 1;
	while(true)
	{
		string brackets;
		cin >> brackets;
		if(brackets[0] == '-')
		{
			break;
		}
		ll i, ops = 0;
		stack<char> bracs;
		for(i = 0; i < brackets.length(); i++)
		{
			if(brackets[i] == '{')
			{
				bracs.push('{');
			}
			else
			{
				if(bracs.empty())
				{
					ops++;
					bracs.push('}');
				}
				else
					bracs.pop();
			}
		}
		ops += bracs.size()/2;
		cout << iter << ". " << ops << endl; 
		iter++;
	}
	return 0;
}
