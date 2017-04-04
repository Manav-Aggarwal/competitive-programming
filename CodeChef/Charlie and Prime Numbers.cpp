#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 5000001
int arr[MAX];
long long i, j;
void sieve()
{
	for(i = 2; i < MAX; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(MAX); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j < MAX; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	long long t;
	cin >> t;
	while(t--)
	{
		long long m, n, sum = 0;
		cin >> m >> n;
		if(m > n)
		{
			cout << 0 << endl;
		}
		else
		{
			for(i = m; i <= n; i++)
			{
				if(arr[i])
				{
					sum += i;
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}
