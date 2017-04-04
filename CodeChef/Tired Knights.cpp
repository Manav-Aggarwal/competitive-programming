#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n, m, h;
		cin >> n >> m;
		h = n/2;
		if(m <= h)
		{
			cout << m + h;
		}
		else if(m > h)
		{
			cout << m - h;
		}
		cout << endl;
	}
	return 0;
}
