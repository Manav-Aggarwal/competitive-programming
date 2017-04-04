/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, n = 1393, d = 985, count = 1;
	for(i = 8; i <= 1000; i++)
	{
		d += n;
		n += 2*(d - n);
		if(d > 1e15 || n > 1e15)
		{
			d/= 1e5;
			n/= 1e5;
		}
		if((ll)(log(n)/log(10)) > (ll)(log(d)/log(10) ) )
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
