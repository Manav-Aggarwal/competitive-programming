/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll powerx(ll x, ll i)
{
	ll ans = 1;
	if(i == 0)
	{
		return 1;
	}
	while(i--)
	{
		ans *= x;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll N, K, L, i, temp;
		cin >> N >> K >> L;
		if(N == 1)
		{
			cout << L << endl;
			continue;
		}
		if(K == 1)
		{
			for(i = 0; i < N; i++)
			{
				cout << 1 << " ";
			}
			cout << endl;
			continue;
		}
		ll arr[N];
		for(i = N-1; i >= 0; i--)
		{
			 temp = (L-1) % powerx(K, N - i);
			 if(temp != 0)
			 {
			 	temp = (temp/powerx(K, N - i - 1))+ 1;
			 }
			 else
			 {
			 	temp++;
			 }
			 arr[i] = temp;
		}
		for(i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
