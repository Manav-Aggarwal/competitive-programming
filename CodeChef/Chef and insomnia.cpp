/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 100011
ll arr[MAXN], n, k;
map<ll, vector<ll> > indices;
map<ll, ll> pairs;
map<ll, bool> isPresent;
void initPairs()
{
	ll x, y, ind;
	for(ll i = 0; i < n; i++)
	{
		x = arr[i];
		y = x - k;
		for(ll j = 1; j <= round(sqrt(y)); j++)
		{
			if(y % j == 0)
			{
				if(x % (y/j) == k)
				{
					for(ind = 0; ind < indices[y/j].size(); ind++)
					{
						if(i < indices[y/j][ind])
						{
							if(!isPresent[i])
							{
								pairs[i] = indices[y/j][ind];
								isPresent[i] = true;
							}
							else if(indices[y/j][ind] < pairs[i])
							{
								pairs[i] = indices[y/j][ind];
							}
						}
					}
				}
			}
			if(x % j == k)
			{
				for(ind = 0; ind < indices[j].size(); ind++)
				{
					if(i < indices[j][ind])
					{
						if(!isPresent[i])
						{
							pairs[i] = indices[j][ind];
							isPresent[i] = true;
						}
						else if(indices[j][ind] < pairs[i])
						{
							pairs[i] = indices[j][ind];
						}
					}
				}
			}
		}
	}
}
void init()
{
	for(ll i = n-1; i >= 0; i--)
	{
		indices[arr[i]].push_back(i);
	}
	initPairs();
}
ll arrSub(ll arr[], ll l, ll r)
{
	ll ans = 0, i, a, b;
	if(l == r)
	{
		return 0;
	}
	else if(l + 1 == r)
	{
		return 1;
	}
	for(i = l; i < r; i++)
	{
		if(isPresent[i] && pairs[i] < r)
		{
			a = i;
			b = pairs[i];
			return arrSub(arr, l, b) + arrSub(arr, a+1, r) - arrSub(arr, a+1, b);
		}
	}
 	return ((r-l)*(r-l+1))/2;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i;
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	init(); 
    cout << arrSub(arr, 0, n);
	return 0;
}
