#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int power(int number, int power, int mod)
{
	int p = 1;
	while(power--)
	{
		p = (p*number) % mod;
	}
	return p;
}
int getpn(int n, int m)
{
	int pn = 1;
	for(int i = 1; i <= n; i++)
	{
		 pn = (pn*power(i, n-i+1, m)) % m;
	}
	return pn;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		int pn = 1, pnr = 1, pr = 1;
		int val[n];
		val[0] = 1;
		for(int i = 1; i <= n; i++)
		{
			 val[i] = getpn(i, m);
		}
		int rs[q];
		for(int i = 0; i < q; i++)
		{
			cin >> rs[i];
			int k = val[n] / (val[rs[i]] * val[n-rs[i]]);
			cout << k;
		}
	}
	return 0;
}
