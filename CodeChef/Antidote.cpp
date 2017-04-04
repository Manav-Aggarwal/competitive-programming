#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, N;
		cin >> a >> b >> N;
		if (N % gcd(a, b) == 0 && N <= max(a, b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
