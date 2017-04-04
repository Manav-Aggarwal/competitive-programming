/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, chaabi;
	cin >> n;
	ll bank[n];
	for(i = 0; i < n; i++)
	{
		cin >> bank[i];
	}
	for(i = 0; i < n; i++)
	{
		chaabi = bank[i];
		j = i-1;
		while(j >= 0 && bank[j] < chaabi)
		{
			bank[j+1] = bank[j];
			j--;
		}
		bank[j+1] = chaabi;
		cout << j + 2 << endl;
	}
	return 0;
}
