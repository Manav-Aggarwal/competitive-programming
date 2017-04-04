#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int fibs[1000001];
long long int gcd(long long int a, long long int b) {return (b) ? gcd(b, a%b) : a;}
long long int mod = 1e9 + 7;
void generatefib()
{
	fibs[1] = 1;
	fibs[2] = 1;
	for(long long int i = 3; i < 1000001; i++)
	{
		fibs[i] = (fibs[i-1] + fibs[i-2]) % mod;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	generatefib();
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int a, b, f;
		cin >> a >> b;
		cout << fibs[gcd(a, b)] << endl;
	}
	return 0;
}
