/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool containsSameDigits(ll num1, ll num2)
{
	ll arr[10], i;
	for(i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	while(num1)
	{
		arr[num1%10]++;
		num1/=10;
	}
	while(num2)
	{
		arr[num2%10]--;
		num2/=10;
	}
	for(i = 0; i < 10; i++)
	{
		if(arr[i] != 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i = 123;
	bool notFound = true;
	while(notFound)
	{
		if(containsSameDigits(i, 2*i) && containsSameDigits(i, 3*i) && containsSameDigits(i, 4*i) && containsSameDigits(i, 5*i) && containsSameDigits(i, 6*i))
		{
			notFound = false;
			break;
		}
		i++;
	}
	cout << i-1;
	return 0;
}
