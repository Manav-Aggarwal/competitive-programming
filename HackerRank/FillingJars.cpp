#include <iostream>
using namespace std;
int avgCand(unsigned long long int n, unsigned long long int m);
int main()
{
	unsigned long long int n, m;
	cin >> n >> m;
    avgCand( n, m );
	return 0;
}
int avgCand(unsigned long long int n, unsigned long long int m)
{
	unsigned long long int sum = 0;
	while(m--)
	{
		unsigned long long int a, b, k;
		cin >> a >> b >> k;
		
			sum += k*(b-a+1);
	}
	cout << sum/n;
	return 0;
}
