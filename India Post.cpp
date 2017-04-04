/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define x first
#define y second
#define INF 999999999
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, xc, yc, q, k, j, dist, minDist, currX, currY, minJ;
	cin >> n;
	pii arr[n];
	for(i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}
	ll nearest[n];
	for(i = 0; i < n; i++)
	{
		k = i;
		minJ = -1;
		minDist = INF;
		xc = arr[k].x; yc = arr[k].y;
		for(j = 0; j < n; j++)
		{
			if(j == k)
				continue;
			dist = abs(xc - arr[j].x) + abs(yc - arr[j].y);
			if(minDist > dist)
			{
				minDist = dist;
				minJ = j;
			}
			else if(minJ != -1 && minDist == dist && (arr[j].y >= 0) && arr[j].x < arr[minJ].x)
			{
				minJ = j;
			}
			else if(minJ != -1 && minDist == dist && (arr[j].y < 0) && arr[j].x > arr[minJ].x)
			{
				minJ = j;
			}
		}
		nearest[i] = minJ + 1;
	}
	cin >> q;
	for(i = 0; i < q; i++)
	{
		cin >> k;
		k--;
		cout << nearest[k] << endl;
	}
	return 0;
}
