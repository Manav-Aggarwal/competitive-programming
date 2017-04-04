/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isTriangleNum(ll num)
{
	double n = (sqrt(1 + 8*num) - 1)/2;
	if(n == (ll)(n))
	{
		return true;
	}
	return false;
}

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
	bool notFound = true;
	ll i = 143, hexaNum;
	while(notFound)
	{
		i++;
		hexaNum = i * (2*i - 1);
		if(isPentagonalNum(hexaNum) && isTriangleNum(hexaNum))
		{
			notFound = false;
			break;
		}
	}
	cout << hexaNum;
	return 0;
}
