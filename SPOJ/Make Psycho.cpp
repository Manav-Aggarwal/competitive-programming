/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll int

bool isPyschoN(ll n)
{
	if(n == 0 || n == 1)
	{
		return false;
	}
	ll i, even = 0, odd = 0, count;
	for(i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			count = 0;
			while(n % i == 0)
			{
				count++;
				n /= i;
			}
			if(count&1)
			{
				odd++;
			}
			else
			{
				even++;
			}
		}
	}
	if(n > 1) odd++;
	if(even > odd)
	{
		return true;
	}
	return false;
}

bool isSubsetSum(ll arr[], ll n, ll k)
{
	if(n == 1 && arr[0] == k)  return true;
	if(n == 2 && (arr[0] + arr[1] == k || arr[0] == k || arr[1] == k)) return true;
	bool subTable[k+1][n+1];
	ll i, j;
	bool b;
	for(i = 0; i <= n; i++)
	{
		subTable[0][i] = true;
	}
	for(i = 1; i <= k; i++)
	{
		subTable[i][0] = false;
	}
	for(i = 1; i <= k; i++)
	{
		for(j = 1; j <= n; j++)
		{
			subTable[i][j] = subTable[i][j-1];
			if(arr[j-1] <= i)
			{
				subTable[i][j] = subTable[i][j] || subTable[i - arr[j-1]][j-1];
			}
		}
	}
	return subTable[k][n];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool isPyscho[1101];
	for(ll i = 0; i < 1101; i++)
	{
		isPyscho[i] = isPyschoN(i);
	}
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k, i, j, num, no = 0, sum = 0;
		cin >> n >> k;
		bool isP = false;
		ll pyschos[n];
		for(i = 0; i < n; i++)
		{
			cin >> num;
			if(isPyscho[num])
			{
				if(num == k)
				{
					isP = true;
				}
				sum += num;
				pyschos[no] = num;
				no++;
			}
		}
		if(sum < k)
		{
			cout << "No" << endl;
		}
		else if(isP || isSubsetSum(pyschos, no, k))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
