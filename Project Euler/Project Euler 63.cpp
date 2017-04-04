/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, count = 3, k;
	for(i = 4; i < 10; i++)
	{
		k = 1;
		while((ll)(log10(pow(i, k))) + 1 == k)
		{
			count++;
			k++;
		}
	}
	cout << count;
	return 0;
}
