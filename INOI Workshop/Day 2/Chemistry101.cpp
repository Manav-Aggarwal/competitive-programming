/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair
bool isDigit(char c) {return (c >= '0' && c <= '9');}
bool isElement(char c) {return (c == 'C' || c == 'O' || c == 'H');}
map<char, ll> massOf;
pair<ll, ll> eval(ll index, string formula)
{
	ll sum = 0, i;
	pair<ll, ll> rt;
	for(i = index; i < formula.length(); i++)
	{
		if(formula[i] == ')')
		{
			if(isDigit(formula[i+1]))
			{
				return mp(sum * (formula[i+1] - '0'), i+1);
			}
			else
				return mp(sum, i);
		}
		else if(isElement(formula[i]))
		{
			sum += massOf[formula[i]];
		}
		else if(isDigit(formula[i]))
		{
			sum += massOf[formula[i-1]]*(formula[i]-'1');
		}
		else if(formula[i] == '(')
		{
			rt = eval(i + 1, formula);
			sum += rt.first;
			i = rt.second;
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string formula;
	cin >> formula;
	ll i, totMass = 0;
	massOf['C'] = 12; massOf['O'] = 16; massOf['H'] = 1; massOf[')'] = 0;
	pair<ll, ll> rtd;
	for(i = 0; i < formula.length(); i++)
	{
		if(isElement(formula[i]))
		{
			totMass += massOf[formula[i]];
		}
		else if(isDigit(formula[i]))
		{
			totMass += massOf[formula[i-1]]*(formula[i]-'1');
		}
		else if(formula[i] == '(')
		{
			rtd = eval(i + 1, formula);
			totMass += rtd.first;
			i = rtd.second;
		}
	}
	cout << totMass << endl;
	return 0;

}
