#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int a, b, n, first, second, temp;
	cin >> a >> b >> n;
	first = a; second = b;
	for(int i  = 1; i < n-1; i++)
	{
		temp = first;
		first = second;
		second = ((first*first) + temp);
	}
	cout << second;
	return 0;
}
