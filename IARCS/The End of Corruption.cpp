/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, m, i, k;
	cin >> n >> m;
	priority_queue<ll> citizens;
	for(i = 0; i < n+m; i++)
	{
		cin >> k;
		if(k == -1)
		{
			cout << citizens.top() << endl;
			citizens.pop();
		}
		else
		{
			citizens.push(k);
		}
	}
	return 0;
}
