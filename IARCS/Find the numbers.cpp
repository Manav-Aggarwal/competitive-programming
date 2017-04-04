/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll arr[4];
bool findNums(ll s, ll p, ll k, ll i)
{
	if(k == 1)
	{
		if(s == p)
		{
			arr[i] = s;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		ll m, lim = sqrt(p);
		for(m = 1; m <= lim; m++)
		{
			if(p % m == 0)
			{
				arr[i] = m;
				if(findNums(s-m, p/m, k-1, i+1))
				{
					return true;
				}
			}
		}
		return false;
	}
	
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("10.in", "r", stdin);
	ll s, p, k, i;
	cin >> s >> p >> k;
	bool hasOne = false;
	if(findNums(s, p, k, 0))
	{
		for(i = 0; i < k; i++)
		{
			if(arr[i] == 1)
			{
				hasOne = true;
			}
		}
		if(hasOne)
		{
			for(i = k-1; i >= 0; i--)
			{
				cout << arr[i] << " ";
			}
		}
		else
		{
			for(i = 0; i < k; i++)
			{
				cout << arr[i] << " ";
			}
		}
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}
