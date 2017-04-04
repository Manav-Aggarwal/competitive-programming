/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll limit = 100000;
ll partitionsArr[limit+1];
ll partitions(ll num, ll mod)
{
	ll i, partition, k, n, sign;
	partitionsArr[0] = partitionsArr[1] = 1;
	for(i = 2; i <= num; i++)
	{
		sign = 1;
		partition = 0;
		n = 1;
		k = (3*n*n-n)/2;
		while(k <= i)
		{
			partition = (partition + sign * partitionsArr[i - k]) % mod;
			n = -n;
			k = (3*n*n-n)/2;
			if(k <= i)
			{
				partition = (partition + sign * partitionsArr[i - k]) % mod;
				n = -n + 1;
			}
			sign = -sign;
			k = (3*n*n-n)/2;
		}
		partitionsArr[i] = partition;
	}
	return partitionsArr[num];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i = 100, mod = 1000000;
	partitions(limit, mod);
	while(true)
	{
		if(partitionsArr[i] % mod == 0)
		{
			break;
		}
		i++;
	}
	cout << i;
	return 0;
}
