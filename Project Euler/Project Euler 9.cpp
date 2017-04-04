/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b, c, i, j;
	double k;
	for(i = 2; i < 1000/3; i++)
	{
		for(j = i; j < 1000/2; j++)
		{
			k = sqrt( (i*i) + (j*j) );
			if(k == floor(k) && (i + j + k == 1000))
			{
				a = i; b = j; c = (ll)k;
			}
		}
	}
	cout << a*b*c;
	return 0;
}
