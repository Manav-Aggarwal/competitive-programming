/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Graph
{
	ll V;
	list<ll> *adj;
public:
	Graph(ll V);
	void addEdge(ll v, ll w);
	bool path_exists(ll v, ll w);
};

Graph::Graph(ll V)
{
	this -> V = V+1;
	adj = new list<ll>[V+1];
}
void Graph::addEdge(ll v, ll w)
{
	adj[v].push_back(w);
}
bool Graph::path_exists(ll v, ll w)
{
	for(list<ll>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if(w == *it)
		{
			return true;
		}
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("1.in", "r", stdin);
	ll n, m, i, j, w, k;
	cin >> n;
	Graph ministers(n);
	for(i = 1; i <= n; i++)
	{
		cin >> m;
		for(j = 0; j < m; j++)
		{
			cin >> w;
			ministers.addEdge(i, w);	
		}
	}
	bool visited[n+1];
	for(i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	list<ll> path;
	path.push_back(1);
	visited[1] = true;
	for(i = 2; i <= n; i++)
	{
		if(!visited[i])
		{
			if(ministers.path_exists(i, path.front()))
			{
				path.push_front(i);
				visited[i] = true;
			}
			else if(ministers.path_exists(path.back(), i))
			{
				path.push_back(i);
				visited[i] = true;
			}
			else
			{
				k = 0;
				for(list<ll>::iterator it = path.begin(); k < path.size(); it++)
				{
					if(ministers.path_exists(*it, i) && ministers.path_exists(i, *(++it)))
					{
						path.insert(--it, i);
						visited[i] = true;
						break;
					}
					k++;
				}
			}
		}
	}
	cout << "YES\n";
	for(list<ll>::iterator it = path.begin(); it != path.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}
