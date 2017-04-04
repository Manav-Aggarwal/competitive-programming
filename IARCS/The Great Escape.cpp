/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii make_pair
class Graph
{
	ll V;
	list<ll> *adj;
public:
	Graph(ll v);
	void addEdge(ll v, ll w);
	ll find_shortest(ll start, ll end, ll n);
};
Graph::Graph(ll v)
{
	this->V = v+1;
	adj = new list<ll>[v+1];
}
void Graph::addEdge(ll v, ll w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
ll Graph::find_shortest(ll start, ll end, ll n)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > jumps;
	ll new_cost, came_from[n+1], cost_so_far[n+1], i;
	pair<ll, ll> temp;
	for(i = 1; i <= n; i++)
	{
		came_from[i] = -1;
		cost_so_far[i] = -1;
	}
	jumps.push(pii(0, start));
	cost_so_far[start] = 0;
	while(!jumps.empty())
	{
		temp = jumps.top();
		if(temp.second == end)
		{
			return temp.first;
		}
		jumps.pop();
		for(list<ll>::iterator it = adj[temp.second].begin(); it != adj[temp.second].end(); it++)
		{
			new_cost = cost_so_far[temp.second] + 1;
			if(cost_so_far[*it] == -1 || new_cost < cost_so_far[*it])
			{
				cost_so_far[*it] = new_cost;
				jumps.push(pii(new_cost, *it));
				came_from[*it] = temp.second;
			}
		}
	}
	return 0;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("10.in", "r", stdin);
	ll n, m, i, b1, b2, start, end;
	cin >> n >> m;
	Graph buildings(n);
	for(i = 0; i < m; i++)
	{
		cin >> b1 >> b2;
		buildings.addEdge(b1, b2);
	}
	cin >> start >> end;
	cout << buildings.find_shortest(start, end, n);
	return 0;
}
