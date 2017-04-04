#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, i = 2;
		cin >> n;
		while(i * i < n)
		{
			if(n % i == 0)
			{
				n/= i;
			}
			i++;
		}
		cout << n << endl;
	}
	
	return 0;
}
