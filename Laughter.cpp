/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll counter = 0;
void recur(string s, string curr, ll prev)
{
	if(curr.length() == 4)
	{
		if(curr == "haha")
			counter++;
	}
	else
	{
		for(ll i = prev+1 ; i < s.length(); i++)
		{
			recur(s, curr+s[i], i);
		}
	}
}
int main()
 {
 
    ll t;
    cin >> t;
    while(t--)
    {
    	string s;
    	cin >> s;
    	for(ll i = 0; i < s.length(); i++)
    	{
    		s[i] = tolower(s[i]);
		}
    	recur(s, "", -1);
    	cout << counter << endl;
    	counter = 0;
	}
    return 0;
}
