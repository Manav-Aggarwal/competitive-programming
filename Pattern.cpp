/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
int main() 
{
 
    string curr, prev = "1";
    ll n;
    cin >> n;
    cout << 1 << endl;
    for(ll i = 2; i <= n; i++)
    {
    	curr = "";
    	ll idx = 0, currNum, count;
    	while(idx < prev.length())
    	{
    		currNum = prev[idx] - '0';
    		count = 0;
	    	while(prev[idx] == currNum + '0')
	    	{
	    		count++;
	    		idx++;
			}
			curr += count + '0';
			curr += currNum + '0';
		}
		cout << curr << endl;
		prev = curr;
	}
    return 0;
}
