/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAXN 100011
list<ll> adj[MAXN];
bool visited[MAXN], possibles[MAXN];
ll n;
void dfs(ll v, ll cnt)
{
	visited[v] = true;
	cnt++;
	for(list<ll>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if(!visited[(*it)])
		{
			dfs((*it), cnt);
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll m, i, h, q;
		cin >> n >> m;
		for(i = 1; i <= n; i++)
		{
			visited[i] = false;
			adj[i].clear();
			possibles[i] = true;
		}
		for(i = 0; i < m; i++)
		{
			cin >> h >> q;
			adj[h].push_back(q);
			possibles[q] = false;
		}
		bool flag = 0, isP;
		for(i = 1; i <= n; i++)
		{
			if(!possibles[i])
				continue;
			isP = 0;
			dfs(i, 0);
			for(h = 1; h <= n; h++)
			{
				if(!visited[h])
				{
					isP = 1;
					break;
				}
			}
			if(!isP)
			{
				flag = 1;
				cout << i << endl;
				break;
			}
			memset(visited, false, sizeof(visited));
		}
		if(!flag)
			cout << -1 << endl;
	}
	return 0;
}
