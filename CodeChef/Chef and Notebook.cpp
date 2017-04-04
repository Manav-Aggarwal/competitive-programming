#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long t;
	cin >> t;
	while(t--)
	{
		long long X, K, Y, N, flag = 0, i, cost, pages;
		cin >> X >> Y >> K >> N;
		X = X - Y;
		for(i = 0; i < N; i++)
		{
			cin >> pages >> cost;
			if(cost <= K && pages >= X)
			{
				flag = 1;
			}
		}
		cout << ((flag == 1) ? "LuckyChef\n" : "UnluckyChef\n");
	}
	return 0;
}
