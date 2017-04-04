#include <iostream>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int k;
		int routes = 1;
		for(long long int i = 0; i<n-1;i++)
		{
			cin >> k;
			routes = (routes*k) % 1234567;
		}
		cout << routes << endl;
		}
	return 0;
}
