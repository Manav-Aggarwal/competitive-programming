#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int nums[100001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int N;
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> nums[i];
		}
		sort(nums, nums + N);
		cout << nums[0] + nums[1] << endl;
	}
	return 0;
}
