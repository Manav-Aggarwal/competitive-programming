#include <bits/stdc++.h>
#define ll long long
using namespace std;
map <ll, bool> nums;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll N, K, l, i;
	cin >> N >> K;
	ll lengths[K]; 
	for(i = 0; i < K; i++)
	{
		cin >> lengths[i];
	}
	nums[1] = true;
	for(i = 0; i < K; i++)
	{
		l = lengths[i] + 1;
		while(l <= N)
		{
			nums[l] = true;
			l += lengths[i];
		}
	}
	cout << N - nums.size();
	return 0;
}
