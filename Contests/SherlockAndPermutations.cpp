#include <iostream>
#include <math.h>
using namespace std;
unsigned long long int factorial[1001];

int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n, m, ans;
		cin >> n >> m;
		long long int mod = (int)pow(10, 9) + 7;
		factorial[0] = 1;
		factorial[1] = 1;
		for(int i = 2; i <= 1000; i++)
		{
			factorial[i] = i * factorial[i-1];
		}
		ans = factorial[n+m-1]/( factorial[n] * factorial[m-1])% mod;
		cout << ans << endl;
	}
	return 0;
}

