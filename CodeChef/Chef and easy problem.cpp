#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool wayToSort(long long int a, long long int b) {return a > b;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long int N, stones = 0;
		cin >> N;
		long long int A[N];
		for(long long int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		sort(A, A + N, wayToSort);
		for(long long int i = 0; i < N; i+=2)
		{
			stones += A[i];
		}
		cout << stones << endl;
	}
	return 0;
}
