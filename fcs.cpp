/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

 ll n, m, capic[1111], i;
bool findIt(ll capacity) 
{
    ll total = 0, curr = 0;
    for(i = 0; i < n; i++) {
        if(capic[i] > capacity) 
			return 0;
        if(curr + capic[i] > capacity) 
			curr = 0;
        if(curr == 0) 
			total++;
        curr += capic[i];
        if(total > m) 
			return 0;
    }
    return 1;
}
 
int main() 
{
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(i = 0; i < n; i++)
            cin >> capic[i];
        ll high = 1000000000, low = 0;
        while(high - low > 0) {
            if(findIt(high)) 
			{
                high = (low+high)/2;
            } 
			else 
			{
                low = high;
                high = high + high / 2;
            }
        }
        cout << high+1 << endl;
	}
    return 0;
}
