/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll ways[32], i;
	ways[0] = 1; ways[1] = 0; ways[2] = 3; ways[3] = 0;
	for(i = 4; i <= 30; i++)
	{
		ways[i] = 4*ways[i-2] - ways[i-4];
	}
	while(true)
	{
		ll num;
		cin >> num;
		if(num == -1)
		{
			break;
		}
		cout << ways[num] << endl;
	}
	return 0;
}
