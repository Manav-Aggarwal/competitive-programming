/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i = 0, j, maxL = 1, length;
	cin >> n;
	ll shelf[n];
	for(i = 0; i < n; i++)
	{
		cin >> shelf[i];
	}
	while(i < n)
	{
		j = i;
		length = 1;
		while(shelf[j] < shelf[j+1] && j < n-1)
		{
			j++;
			length++;
		}
		maxL = max(maxL, length);
		i = j+1;
	}
	cout << n-maxL;
	return 0;
}
