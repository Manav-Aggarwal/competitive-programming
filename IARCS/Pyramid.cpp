/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<ll> blocks;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, d1, d2, maxL = 0;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> d1 >> d2;
		blocks.push_back(min(d1, d2));
	}
	sort(blocks.begin(), blocks.end());
	for(i = 0; i < n; i++)
	{
		if(blocks[i] > maxL)
		{
			maxL++;
		}
	}
	cout << maxL;
	return 0;
}
