#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int power2(unsigned long long int n, unsigned long long int m)
{
	unsigned long long int p = 1;
	while(n--)
	{
		p = (p*2) % m;
	}
	return p;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned long long int n, m, total, sum = 2;
	cin >> n >> m;
	total = power2(n, m);
	for(unsigned long long int i = 2; i < n; i++)
	{
		if(!(n%i))
		{
			unsigned long long int k = power2(i, m);
			sum = (sum + k) % m;
		}
	}
	total = (total - sum) % m;
	cout << total << endl;
	return 0;
}  
