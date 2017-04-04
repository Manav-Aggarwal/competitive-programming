#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int W[100000], sums[100001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	sums[0] = 0;
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int N, M, sum = 0, mx = 0, j = 0;
		cin >> N;
		for(long long int i = 0; i < N; i++)
		{
			cin >> W[i];
			sums[i+1] = 0;
			sums[i+1] = sums[i] + W[i];
		}
		cin >> M;
		for(int i = M; i <= N; i++)
		{
			j = i-M;
			sum = sums[i] - sums[j];
			mx = max(mx, sum);
		}
		cout << mx << endl;
	}
	return 0;
}
