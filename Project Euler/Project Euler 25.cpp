/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, n, carry, seqN;
	cin >> n;
	ll arrNum1[n], arrNum2[n], arrNext[n];
	for(i = 0; i < n; i++)
	{
		arrNum1[i] = arrNum2[i] = arrNext[i]= 0;
	}
	arrNum1[0] = arrNum2[0] = 1;
	seqN = 2;
	while(arrNext[n-1] == 0)
	{
		seqN++;
		carry = 0;
		for(i = 0; i < n; i++)
		{
			arrNext[i] = arrNum1[i] + arrNum2[i] + carry;
			carry = 0;
			if(arrNext[i] > 9)
			{
				carry = arrNext[i]/10;
				arrNext[i] %= 10;
			}
			arrNum1[i] = arrNum2[i];
			arrNum2[i] = arrNext[i];
		}
	}
	cout << seqN;
	return 0;
}
