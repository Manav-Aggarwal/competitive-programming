/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, maxLen = 0, len, numWithLargest, rem, j;
	for(i = 3; i < 1000; i+=2)
	{
		bool arr[i];
		for(j = 0; j < i; j++)
		{
			arr[j] = false;
		}
		rem = 1; len = 0;
		while(arr[rem] == false && rem != 0)
		{
			arr[rem] = true;
			rem *=10;
			rem %= i;
			len++;
		}
		if(maxLen < len)
		{
			maxLen = len;
			numWithLargest = i;
		}
	}
	cout << numWithLargest;
	return 0;
}
