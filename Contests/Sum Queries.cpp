#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	freopen("test.in", "r", stdin);
	int N, M;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int s = N*(N+1)/2;
	int arrsums[s];
	int sum = 0;
	for(int i = 0; i < N; i++)
		{
			for(int j = i; j < N; j++)
			{
				int k = sum + j-i;
				arrsums[k] = arr[i] * arr[j];
			}
			sum += N-i;
		}
	cin >> M;
	while(M--)
	{
		int n1, n2, sum = 0;
		cin >> n1 >> n2;
		int tsum = (abs(n2-n1) + 1) * (abs(n2-n1) + 2)/2;
		for(int i = 0; i < tsum; i++)
		{
			
		}
		cout << sum << endl;
	}
	return 0;
}
