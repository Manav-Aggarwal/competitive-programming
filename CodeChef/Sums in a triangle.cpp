#include <bits/stdc++.h>
using namespace std;
#define rf freopen("test.in", "r", stdin);
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//rf
	int t;
	cin >> t;
	while(t--)
	{
		int matrix[100][100] = {0};
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				cin >> matrix[i][j];
			}
		}
		for(int i = n-2; i >= 0; i--)
		{
			for(int j = 0; j <= i; j++)
			{
				matrix[i][j] += matrix[i+1][j] > matrix[i+1][j+1] ? matrix[i+1][j] : matrix[i+1][j+1];
			}
		}
		cout << matrix[0][0] << endl;
	}
	return 0;
}
