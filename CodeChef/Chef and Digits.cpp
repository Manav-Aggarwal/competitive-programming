#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	//freopen("test.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	string number;
	cin >> number;
	while(m--)
	{
		int x, sumg0 = 0, suml0 = 0;
		cin >> x;
		x--;
		int b[n];
		for(int i = 0; i < x; i++)
		{
			b[i] = (number[x] - '0') - (number[i] - '0');
			if(b[i] > 0)
			{
				sumg0 += b[i];
			}
			else if(b[i] < 0)
			{
				suml0 += b[i];
			}
		}
		cout << sumg0 - suml0 << endl;
	}
	return 0;
}
