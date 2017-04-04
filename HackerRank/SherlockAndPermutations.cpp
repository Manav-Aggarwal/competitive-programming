#include <iostream>
#include <math.h>
using namespace std;
long long int factorial(long long int n);
int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n, m, ans;
		cin >> n >> m;
		long long int mod = (int)pow(10, 9) + 7;
		ans = factorial(n+m-1)/( factorial(n) * factorial(m-1))% mod;
		cout << ans << endl;
	}
	
	return 0;
}
long long int factorial(long long  n)
{
	return (n==1|| n==0) ? 1 : factorial(n-1) * n;
}
