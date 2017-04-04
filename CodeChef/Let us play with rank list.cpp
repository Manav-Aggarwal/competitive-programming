#include <bits/stdc++.h>
using namespace std;
int main()
{	int T;
	cin >> T;
	while(T--)
	{
		long long int n, s, sum, count;
		cin >> n >> s;
		sum = n*(n+1)/2;
		if(sum == s)
		{
			count = 0;
		}
		else if(n == s)
		{
			count = s - 1;
		}
		else
		{
			count = 0;
			int a[n+1];
			for(int i = 0; i <= n; i++)
			{
				a[i]  = i;
			}
			for(int i = n; i >= 1; i--)
			{
				if(sum > (s+a[i]-1))
				{
					s+= a[i] - 1;
					count++;
				}
				else
				{
					count++;
					break;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
