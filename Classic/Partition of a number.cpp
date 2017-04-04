/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll partitions(ll num)
{
	ll i, partitions[num+1], partition, k, n, sign;
	partitions[0] = partitions[1] = 1;
	for(i = 2; i <= num; i++)
	{
		sign = 1;
		partition = 0;
		n = 1;
		k = (3*n*n-n)/2;
		while(k <= i)
		{
			partition += sign * partitions[i - k];
			n = -n;
			k = (3*n*n-n)/2;
			if(k <= i)
			{
				partition += sign * partitions[i-k];
				n = -n + 1;
			}
			sign = -sign;
			k = (3*n*n-n)/2;
		}
		partitions[i] = partition;
	}
	return partitions[num];
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << partitions(55754);
	return 0;
}
