/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	vector<ll> num;
	cin >> t;
	while(t--)
	{
		num.clear();
		ll n, i, k;
		bool flag = true;
		cin >> n;
		for(i = 0; i < n; i++)
		{
			cin >> k;
			num.push_back(k);
		}
		for(i = 1; i < n; i++)
		{
			if(num[i-1] < num[i])
			{
				flag = false;
			}
		}
		if(flag)
			cout << "-1";
		else
		{
			next_permutation(num.begin(), num.end());
			for(i = 0; i < n; i++)
			{
				cout << num[i];
			}
		}
		cout << endl;
	}
	return 0;
}
