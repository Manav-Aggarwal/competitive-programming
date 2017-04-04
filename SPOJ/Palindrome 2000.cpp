/* Written By Manav Aggarwal */
#include <iostream>
using namespace std;
#define endl '\n'
int lcs[2][5555];
int main()
{	
    ios_base::sync_with_stdio(false);
	int n, i, j;
	cin >> n;
	string s, rev;
	cin >> s;
	rev = s;
	for(j = 0; j < n; j++)
	{
		lcs[0][j] = 0;
		rev[j] = s[n-j-1];
	}
	lcs[0][n] = 0;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
			{
				lcs[(i%2)][j] = 0;
			}
			else if(s[i-1] != rev[j-1])
			{
				lcs[(i%2)][j] = max(lcs[!(i%2)][j], lcs[(i%2)][j-1]);
			}
			else
			{
				lcs[(i%2)][j] = 1 + lcs[!(i%2)][j-1];
			}
		}
	}
	printf("%d\n", n - lcs[!(i%2)][n]);
	return 0;
}
