/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isPentagonalNum(ll num)
{
	double n = (sqrt(1 + 24*num) + 1)/6;
	if(n == (ll)(n))
	{
		return true;
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll j = 1, k, num1, num2, minNum = INT_MAX;
	bool notFound = true;
	while(notFound)
	{
		j++;
		num1 = (j * (3*j - 1))/2;
		for(k = j + 1; k < 3000; k++)
		{
			num2 = (k * (3*k - 1))/2;
			if(isPentagonalNum(num1+num2) && isPentagonalNum(num2 - num1))
			{
				minNum = num2 - num1;
				notFound = false;
			}
		}
	}
	cout << minNum;
	return 0;
}
