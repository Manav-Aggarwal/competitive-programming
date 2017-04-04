#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long counts[10001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int i, n, num, max = 0, maxi = 0;
		for(i = 0; i < 10001; i++)
		{
			counts[i] = 0;
		}
		cin >> n;
		for(i = 0; i < n; i++)
		{
			cin >> num;
			counts[num]++;
		}
		for(i = 0; i < 10001; i++)
		{
			if(max < counts[i])
			{
				max = counts[i];
				maxi = i;
			}
		}
		cout << maxi << " " << max << endl;
	}
	return 0;
}
