/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll arr[321];
	arr[0] = 1;
	ll i, j, carry = 0, sum = 0, n;
	cin >> n;
	for(i = 1; i < 321; i++)
	{
		arr[i] = 0;
	}
	for(i = 0; i < n; i++)
	{
		carry = 0;
		for(j = 0; j < 321; j++)
		{
			arr[j] = (arr[j]*2) + carry;
			carry = 0;
			if(arr[j] > 9)
			{
				carry = arr[j] / 10;
				arr[j] %= 10;
			}
		}
	}
	for(i = 0; i < 321; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	return 0;
}
