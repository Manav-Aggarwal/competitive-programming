/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isPalin(string str)
{
	for(ll i = 0; i < str.length()/2; i++)
	{
		if(str[i] != str[str.length()-1-i])
		{
			return false;
		}
	}
	return true;
}
ll numIns(string s)
{
	char beechka;
	beechka = s[s.length()/2];
	ll i, count = 0;
	bool passed = false;
	for(i = 0; i < s.length(); i++)
	{
		if(i == s.length()/2)
		{
				passed = true;
		}
		if(s[i] == beechka)
		{
			count++;
		}
		else if(!passed)
		{
			count = 0;
		}
		else
		{
			break;
		}
	}
	return count+1;
}
void make_palin(string s, ll b, ll e, pair<bool, ll> *isPalin)
{
	ll i, start, end, size;
	for(i = b; i < e; i++)
	{
		isPalin[i] = make_pair(false, -1);
	}
	if((e-b) % 2 == 0)
	{
		start = (e-b)/2 - 1 + b;
		end = (e-b)/2 + b;
		size = 1;
		if(start >= b && end < e && s[start] == s[end])
		{
			isPalin[start] = make_pair(true, size);
			isPalin[end] = make_pair(true, -size);
		}
	}
	else
	{
		start = (e -b)/2 - 1 + b;
		end = (e-b)/2 + 1 + b;
		isPalin[start + 1] = make_pair(true, 0);
		size = 2;
		if(start >= b && end < e && s[start] == s[end])
		{
			isPalin[start] = make_pair(true, size);
			isPalin[end] = make_pair(true, -size);
		}
	}
	start--; end++; size+=2;
	while(start >= b && end < e)
	{
		if(s[start] == s[end] && isPalin[start+1].first)
		{
			isPalin[start] = make_pair(true, size);
			isPalin[end] = make_pair(true, -size);
		}
		start--; end++; size += 2;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t, i, j;
	cin >> t;
	while(t--)
	{
		ll count = 0, start, end, size;
		string s, temp;
		cin >> s;
		if(isPalin(s))
		{
			cout << numIns(s) << endl;
			continue;
		}
		pair<bool, ll> isPaline[s.length()], isPalinb[s.length()];
		make_palin(s, 0, s.length()-1, isPaline);
		make_palin(s, 1, s.length(), isPalinb);
		for(i = 0; i <= s.length()/2; i++)
		{
			if(isPalinb[i].first)
			{
				cout << true << endl;
			}
		}
	}
	return 0;
}
