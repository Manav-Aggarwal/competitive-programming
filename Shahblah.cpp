/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
int maxVal(ll x, ll y, ll z, ll n)
{
    ll table[n+1], i, j;
    table[0] = 0;
    for (i = 1; i <= n; i++)
        table[i] = INT_MIN;
 
    for (i = 1; i <= n; i++)
    {
          if (x <= i)
          {
              int sub_res = table[i-x];
              if (sub_res + 1 > table[i])
                  table[i] = sub_res + 1;
          }
          if (y <= i)
          {
              int sub_res = table[i-y];
              if (sub_res + 1 > table[i])
                  table[i] = sub_res + 1;
          }
          if (z <= i)
          {
              int sub_res = table[i-z];
              if (sub_res + 1 > table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[n];
}
int main() 
{
 	ll t;
 	cin >> t;
 	while(t--)
 	{
 		ll x, y, z, n;
 		cin >> n >> x >> y >> z;
 		cout << maxVal(x, y, z, n) << endl;
	}
    return 0;
}
