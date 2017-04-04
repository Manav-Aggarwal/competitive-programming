#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false);
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int k, count = 0, num = 5;
		cin >> k;
		while((k/num )> 0)
		{
			count += k/num;
			num*=5;
		}
		cout << count << endl;
	}
	return 0;
}
