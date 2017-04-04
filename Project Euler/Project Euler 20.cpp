/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll arr[200];
	ll i, j, carry, sum = 0, n;
	cin >> n;
	for(i = 1; i < 200; i++)
	{
		arr[i] = 0;
	}
	arr[0] = 1;
	for(i = 2; i <= n; i++)
	{
		carry = 0;
		for(j = 0; j < 200; j++)
		{
			arr[j] = (arr[j] * i) + carry;
			carry = 0;
			if(arr[j] > 9)
			{
				carry = arr[j]/10;
				arr[j] %= 10;
			}
		}
	}
	for(i = 0; i < 200; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	return 0; 
}
