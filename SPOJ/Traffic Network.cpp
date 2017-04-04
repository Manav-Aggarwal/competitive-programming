/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair
#define pii pair<ll, ll>
#define INF 9999999999

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll tests;
	cin >> tests;
	while(tests--)
	{
		ll n, m, k, s, t, i, j, di, ci, li, alt;
		cin >> n >> m >> k >> s >> t;
		list<pair<ll, pii> > paths[n+1];
		pair<pii, ll> currK;
		pii currKf; ll currKs;
		for(i = 0; i < m; i++)
		{
			ll di, ci, li;
			cin >> di >> ci >> li;
			paths[di].push_back(mp(li, mp(ci, 0)));
		}
		ll minDistance = INF;
		for(i = 0; i < k; i++)
		{
			cin >> di >> ci >> li;
			paths[di].push_back(mp(li, mp(ci, 1)));
			paths[ci].push_back(mp(li, mp(di, 1)));
		}
		ll dist[n+1][2];
		bool visited[n+1][2];
		for(j = 1; j <= n; j++)
		{
			dist[j][0] = INF;
			dist[j][1] = INF;
			visited[j][0] = false;
			visited[j][1] = false;
		}
		priority_queue<pair<ll, pii>, vector<pair<ll, pii> >, greater<pair<ll, pii> > > frontier;
		frontier.push(mp(0, mp(s, 0)));
		pair<ll, pii> curr, next;
		while(!frontier.empty())
		{
			curr = frontier.top();
			frontier.pop();
			if(visited[curr.second.first][curr.second.second])
				continue;
			visited[curr.second.first][curr.second.second] = true;
			if(curr.second.first == t)
			{
				minDistance = curr.first;
				break;
			}
			for(list<pair<ll, pii> >::iterator it = paths[curr.second.first].begin(); it != paths[curr.second.first].end(); it++)
			{
				next = *it;
				if(curr.second.second && next.second.second)
				{
					continue;
				}
				frontier.push(mp(next.first+curr.first, mp(next.second.first, curr.second.second|next.second.second)));
			}
		}
		if(minDistance == INF)
			cout << -1 << endl;
		else
			cout << minDistance << endl;
	}
	return 0;
}
