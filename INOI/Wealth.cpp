/*Manav Aggarwal
36110
Problem: Wealth Disparity*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define first f
#define second s
#define MAX 100111
#define INF 111111111
ll a[MAX], p[MAX], visited[MAX], maxDiff;
vector<ll> adjList[MAX];
ll dfs(ll start, ll maxTill, ll n)
{
	stack<ll> frontier;
	frontier.push(start);
	maxTill = max(maxTill, a[start]);
	visited[start] = 1;
	ll i;
	for(i = 0; i < adjList[start].size(); i++)
	{
		if(!visited[adjList[start][i]])
		{
			maxDiff = max(maxDiff, maxTill - a[adjList[start][i]]);
			dfs(adjList[start][i], maxTill, n);
		}
	}
	
}
int main()
{
	//freopen("2_6.in", "r", stdin);
	ll n, i, manager;
	maxDiff = -INF;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		visited[i] = 0;
		adjList[i].clear();
	}
	for(i = 1; i <= n; i++)
	{
		cin >> p[i];
		if(p[i] == -1)
			manager = i;
		else
		{
			adjList[p[i]].push_back(i);
		}
	}
	dfs(manager, a[manager], n);
	cout << maxDiff << endl;
	return 0;
}
