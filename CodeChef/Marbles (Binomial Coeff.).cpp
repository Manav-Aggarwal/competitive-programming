#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000001
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long n, k, p = 1, i;
		cin >> n >> k;
		n--; k--;
		k = min(k, n-k);
		for(i = 1; i <= k; i++)
		{
			p*= n--;
			p/=i;
		}
		cout << p << endl;
	}
	return 0;
}
