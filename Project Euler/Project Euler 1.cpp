#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull get(ull n, ull k)
{
	return n*(k/n)*((k/n)+1)/2;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ull n;
		cin >> n;
		n--;
		cout << get(3, n) + get(5, n) - get(15, n) <<  endl;
	}
	return 0;
}
