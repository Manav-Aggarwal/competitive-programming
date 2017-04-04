#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int num;
		cin >> num;
		long long int sum = 0;
		for(int i = num; i >= 1; i--)
		{
			sum += i-1;
		}
		cout << sum << endl;
	}
	return 0;
}
