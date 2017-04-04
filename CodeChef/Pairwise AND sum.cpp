#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int power[30];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, sum = 0,  i , j, k;
	for(i = 0; i < 30; i++)
	{
		power[i] = 0;
	}
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> k;
		for(j = 0; j < 30; j++)
		{
			if(k & (1 << j))
			{
				power[j]++;
			}
		}
	}
	for(i = 0; i < 30; i++)
	{
		sum += (power[i] * (power[i] - 1))* (1 << i);
	}
	cout << sum/2 << endl;
	return 0;
}
