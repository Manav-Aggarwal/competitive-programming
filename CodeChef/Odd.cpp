#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int power(long long int len)
{
	long long p = 1;
	while(len--)
	{
		p*=2;
	}
	return p;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		long long int len = log2(n);
		cout << power(len) << endl;
	}
	return 0;
}
