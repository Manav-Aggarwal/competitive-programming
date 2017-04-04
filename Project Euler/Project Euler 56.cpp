/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b, maxSum = 0, i, p, carry, sum = 0, digits;
	bool found = true;
	for(a = 99; a >= 2; a--)
	{
		for(b = 99; b >= 2; b--)
		{
			digits = 0; found = true;
			sum = 0;
			ll arr[200];
			for(i = 1; i < 200; i++)
			{
				arr[i] = 0;
			}
			arr[0] = 1;
			carry = 0;
			for(p = 0; p < b; p++)
			{
				i = 0;
				for(i = 0; i < 200; i++)
				{
					arr[i] = arr[i]*a + carry;
					carry = 0;
					if(arr[i] > 9)
					{
						carry = arr[i]/10;
						arr[i] %= 10;
					}
				}
			}
			for(i = 199; i >= 0; i--)
			{
				if(arr[i] != 0 && found)
				{
					found = false;
				}
				sum += arr[i];
				if(!found)
				{
					digits++;
				}
			}
			if(maxSum > 9*digits)
			{
				break;
			}
			maxSum = max(maxSum, sum);
		}
	}
	cout << maxSum;
	return 0;
}
