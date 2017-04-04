#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
unsigned long long sums[1000001];
void pre()
{
	sums[1] = 0;
	sums[2] = 2;
	sums[3] = 8;
	for(long long i = 4; i < 1000001; i++)
	{
		sums[i] = sums[i-1] + ((i-1) * i);
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	pre();
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		cout << sums[n] << endl;
	}
	return 0;
}
