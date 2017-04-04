#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll M = 100000;
ll arr[100001];
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(M); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j <= M; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	int n;
	cin >> n;
	cout << 2;
	for(ll i = 3; i <= n; i+=2)
	{
		if(arr[i] == 1)
		{
			cout << i << ", ";
		}
	}
	return 0;
}
