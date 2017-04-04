#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned long long int t;
	cin >> t;
	while(t--)
	{
		unsigned long long int n, p = 1; 
		cin >> n;
		while(p < n)
		{
			p = p << 1;
		}
		p = p >> 1;
		cout << ((n - p) << 1) + 1 << endl;
	}
	return 0;
}
