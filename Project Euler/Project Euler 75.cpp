/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;}
ll const limit = 1500000;
ll triples[limit+1];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll count = 0, m, n, a, b, c, sum;
	for(m = 2; m < sqrt(limit/2); m++)
	{
		for(n = 1; n < m; n++)
		{
			if((m+n)%2 == 1 && gcd(m, n) == 1)
			{
				a = m*m - n*n;
				b = 2*m*n;
				c = m*m + n*n;
				sum = a + b + c;
				while(sum <= limit)
				{
					triples[sum]++;
					if(triples[sum] == 1)
						count++;
					if(triples[sum] == 2)
						count--;
					sum += a + b + c;
				}
			}
		}
	}
	cout << count;
	return 0;
}
