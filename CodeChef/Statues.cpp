#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, t = 1;
	cin >> n;
	while(n)
	{
		long long int sum = 0, i, d, m = 0;
		long long int arr[n];
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		d = sum/n;
		for(i = 0; i < n; i++)
		{
			if((d - arr[i]) > 0)
			{
				m += (d-arr[i]);
			}
		}
		cout << "Set #" << t << endl << "The minimum number of moves is " << m << "." << endl << endl;
		t++;
		cin >> n;
	}
	return 0;
}
