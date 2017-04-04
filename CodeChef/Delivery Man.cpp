#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int getSum(long long int N, long long int A[], long long int B[], long long int x, long long int y)
{
	long long int sum = 0;
	for(unsigned long long int i = 0; i < N; i++)
	{
		if(A[i] > B[i])
		{
			if(x > 0)
			{
				x--;
				sum += A[i];
			}
			else
			{
				y--;
				sum += B[i];
			}
				
		}
		else
		{
			if(y > 0)
			{
				y--;
				sum += B[i];
			}
			else
			{
				x--;
				sum += A[i];
			}
		}
	}
	return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int N, x , y, sum;
	cin >> N >> x >> y;
	long long int A[N], B[N];
	for(long long int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for(long long int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sum = max(getSum(N, A, B, x, y), getSum(N, B, A, y, x));
	cout << sum << endl;
	return 0;
}
