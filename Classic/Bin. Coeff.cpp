#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int min(int a, int b);
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}
 
// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}

int main()
{	
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	cout << binomialCoeff(n, k);
	return 0;
}
