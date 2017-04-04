/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair
bool isDigit(char c) {return (c >= '0' && c <= '9');}
bool isElement(char c) {return (c == 'C' || c == 'O' || c == 'H');}
map<char, ll> massOf;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string formula;
	cin >> formula;
	ll i, totMass = 0, tp, k;
	massOf['C'] = 12; massOf['O'] = 16; massOf['H'] = 1; massOf[')'] = 0;
	pair<ll, ll> rtd;
	stack<ll> cmp;
	cmp.push(0);
	for(i = 0; i < formula.length(); i++)
	{
		tp = cmp.top(); cmp.pop();
		if(isElement(formula[i]))
		{
			tp += massOf[formula[i]];
			cmp.push(tp);
		}
		else if(isDigit(formula[i]))
		{
			if(formula[i-1] != ')')
			{
				tp += massOf[formula[i-1]]*(formula[i]-'1');
			}
			else
			{
				tp *= (formula[i] - '0');
			}
			cmp.push(tp);
		}
		else if(formula[i] == '(')
		{
			cmp.push(tp);
			cmp.push(0);
		}
		else if(formula[i] == ')')
		{
			k = cmp.top();
			tp += k; 
			cmp.pop();
			cmp.push(tp);
		}
	}
	cout << cmp.top() << endl;
	return 0;
}
