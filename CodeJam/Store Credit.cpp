#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int t;
	cin >> t;
	for(int z = 1; z <= t; z++)
	{
		int C, I, s, i, j, flag = 0;
		cin >> C >> I;
		int prices[I];
		for(i = 0; i < I; i++)
		{
			cin >> prices[i];
		}
		for(i = 0; i < I; i++)
		{
			s = C - prices[i];
			for(j = i+1; j < I; j++)
			{
				if(prices[j] == s)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
		cout << "Case #" << z << ": " << i+1 << " " << j+1 << endl;
	}
	return 0;
}
