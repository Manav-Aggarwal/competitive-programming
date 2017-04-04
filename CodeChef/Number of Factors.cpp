#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int numfacts(long long int n)
{
	long long int count = 1;
	for(int i = 1; i <= sqrt(n); i++)
	{
		if(n%i == 0)
		{
			count++;
		} 
	}
	return count;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long int N, num = 1, k;
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> k;
			num *= k;
		}
		cout << numfacts(num) << endl;
	}
	return 0;
}
