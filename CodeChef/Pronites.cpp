#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int max(int a, int b)
{
    return (a > b)? a : b;
}
int min4(int a, int b, int c, int d, int e, int f, int g)
{
	return min(min(min(min(min(min(a, b), c), d), e), f), g);
}
int lcs(string X, string Y, int n)
{
   int L[n+1][n+1];
   int i, j;
   for (i=0; i<=n; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[n][n];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int n, sum = 0;
		cin >> n;
		string s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		int len = min4(lcs(s1, s2, n), lcs(s2, s3, n), lcs(s3, s4, n), lcs(s4, s1, n), lcs(s4, s2, n), lcs(s2, s3, n), lcs(s1, s3, n));
		cout << len << endl;
	}
	return 0;
}
