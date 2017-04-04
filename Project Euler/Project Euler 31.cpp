/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll currencies[8] = {1, 2, 5, 10, 20, 50, 100, 200};
	ll amt = 200, i, j;
	//cin >> amt;
	ll ways[amt+1];
	for(i = 0; i <= amt; i++)
	{
		ways[i] = 0;
	}
	ways[0] = 1;
	for(i = 0; i < 8; i++)
	{
		for(j = currencies[i]; j <= amt; j++)
		{
			ways[j] += ways[j - currencies[i]];
		}
	}
	cout << ways[amt] << endl;
	return 0;
}
