/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
set<string> vis;
void recur(string src, ll len, ll prev, string curr)
{
	ll i = prev+1;
	if(curr.length() == len)
	{
		vis.insert(curr);
	}
	else
	{
		while(i < src.length())
		{
			recur(src, len, i, curr+src[i]);
			i++;
		}
	}
}
int main() 
{
    recur("gargantuan", 5, -1, "");
   	cout << vis.size();
    return 0;
}
