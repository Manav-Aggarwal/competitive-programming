/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 111111
#define INF 111111111
ll arr[MAX], parent[MAX], maxDiff = -INF, visited[MAX];
vector<ll> adjList[MAX];
void dfs(ll start, ll maxTill)
{
	visited[start] = 1;
	maxTill = max(maxTill, arr[start]);
	ll i;
	for(i = 0; i < adjList[start].size(); i++)
	{
		if(!visited[adjList[start][i]])
		{
			maxDiff = max(maxDiff, maxTill - arr[adjList[start][i]]);
			dfs(adjList[start][i], maxTill);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll n, i;
	cin >> n;
	ll manager;
	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
		visited[i] = 0;
	}
	for(i = 1; i <= n; i++)
	{
		cin >> parent[i];
		if(parent[i] == -1)
		{
			manager = i;
		}
		else
		{
			adjList[parent[i]].push_back(i);
		}
	}
	dfs(manager, arr[manager]);
	cout << maxDiff << endl;
	return 0;
}
