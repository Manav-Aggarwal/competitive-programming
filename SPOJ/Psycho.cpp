/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, i, even = 0, odd = 0, count;
		cin >> n;
		for(i = 2; i*i <= n; i++)
		{
			if(n % i == 0)
			{
				count = 0;
				while(n % i == 0) 
				{
					count++;
					n /= i;
				}
				if(count&1)
				{
					odd++;
				}
				else
				{
					even++;
				}
			}
		}
		if(n > 1) odd++;
		if(even > odd)
		{
			cout << "Psycho Number" << endl;
		}
		else
		{
			cout << "Ordinary Number" << endl;
		}
	}
	return 0;
}
