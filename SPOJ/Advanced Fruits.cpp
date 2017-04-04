/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

string findShortest(string f1, string f2)
{
	string set1, set2;
	ll i, j;
	for(i = 0; i < max(f1.length(), f2.length()); i++)
	{
		if(i < f1.length())
			set1 += '0';
		if(i < f2.length())
			set2 += '0';
	}
	for(i = 0; i < f1.length(); i++)
	{
		for(j = 0; j < f2.length(); j++)
		{
			
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string f1, f2;
	while(scanf("%s",&f1) != EOF)
	{
	   cin >> f2;
	   cout << findShortest(f1, f2) << endl;
	}
	return 0;
}
