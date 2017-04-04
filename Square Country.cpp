/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, minN;
	cin >> n;
	ll arr[n+1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for(i = 3; i <= n; i++)
	{
		minN = arr[i-1] + 1;
		for(j = 2; j*j <= i; j++)
		{
			if(minN > arr[i - j*j] + 1)
			{
				minN = arr[i - j*j] + 1;
			}
		}
		arr[i] = minN;
	}
	cout << arr[n];
	return 0;
}
