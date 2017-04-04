#include <iostream>
using namespace std;
int main()
{
	long long int N;
	int mod = 15746;
	cin >> N;
	long long int first, second = 1;
	long long int temp;
	for(long long int i = 1; i < N; i++)
	{
		temp = first % mod;
		first = second % mod;
		second = (temp + second) % mod; 
	}
	cout << second % mod;
	return 0; 
}
