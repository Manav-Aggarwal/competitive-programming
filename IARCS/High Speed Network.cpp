/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define inf INT_MAX
#define M 2000

ll findMin(ll keys[], ll n, map<ll, bool> mst)
{
	ll minNum = inf, minInd, i;
	for(i = 1; i < n; i++)
	{
		if(keys[i] < minNum && !mst[i] && keys[i] != inf)
		{
			minInd = i;
			minNum = keys[i];
		}
	}
	return minInd;
}
ll adjM[M+1][M+1];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll n, i, j;
	cin >> n;
	ll keys[n], ind, cost = 0;
	map<ll, bool> mst;
	for(i = 0; i < n; i++)
	{
		keys[i] = inf;
		for(j = 0; j < n; j++)
		{
			cin >> adjM[i][j];
			if(adjM[i][j] == 0)
				adjM[i][j] = inf;
		}
	}
	/*Prim's Algorithm*/
	keys[1] = 0;
	while(mst.size() < n-1)
	{
		ind = findMin(keys, n, mst);
		cost += keys[ind];
		mst[ind] = true;
		for(i = 1; i < n; i++)
		{
			if(adjM[ind][i] < keys[i])
			{
				keys[i] = adjM[ind][i];
			}
		}
	}
	cout << cost;
	return 0;
}
