/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 999999999999
#define mp make_pair
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, m, b, i, j, k, u, v, d, z;
		cin >> n >> m >> b;
		ll graph[n][n], dist[n][n];
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				graph[i][j] = INF;
				if(i == j)
				{
					graph[i][j] = 0;
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			cin >> u >> v >> d;
			if(graph[u][v] > d)
			{
				graph[u][v] = d;
				graph[v][u] = d;
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				dist[i][j] = graph[i][j];
			}
		}
		for(k = 1; k <= n; k++)
		{
			for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++)
				{
					if(dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				cout << i << " to " << j << " is " << dist[i][j] << endl;
			}
		}
		/*cin >> z;
		vector<pair<ll, pair<ll, ll> > > orders;
		ll best = INF, secBest = INF;
		for(i = 0; i < z; i++)
		{
			cin >> u >> v >> d;
			orders.push_back(mp(d, mp(u, v)));
			if(dist[b][u] < best)
			{
				best = dist[b][u];
			}
		}
		for(i = 0; i < z; i++)
		{
			if(orders[i].second.first != best && dist[orders[i].second.first][b] < secBest)
				secBest = orders[i].second.first;
		}*/
	}
	return 0;
}
