#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int mod = 1e9 + 7;
	while(t--)
	{
		int L, R;
		cin >> L >> R;
		int N = R - L + 1;
		int xmatrix[N][N];
		for(int i = L; i <= R; i++)
		{
			for(int j = i; j <= R; j++)
			{
				xmatrix[i-L][j-L] = j;
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				cout << xmatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
