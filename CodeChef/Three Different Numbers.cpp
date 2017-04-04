#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t , mod = 1e9 + 7;
	cin >> t;
	while(t--)
	{
		long long int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		long long int n1, n2, n3;
		n1 = arr[0]; n2 = arr[1] - 1; n3 = arr[2] - 2;
		cout << (((n1 % mod) * (n2 % mod) % mod) *(n3 % mod)%mod)<< endl; 
	}
	return 0;
}
