#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, k, count = 0;
	cin >> n >> k;
	for(long long int i = 0; i < n; i++)
	{
		long long int t;
		cin >> t;
		if(t%k == 0)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
