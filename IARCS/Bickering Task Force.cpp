/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Graph
{
    int V;
public:
    Graph(int V);
    list<int> *adj;
    void addEdge(int v, int w);
    ll Size(ll v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    adj[w].push_back(v);
}
ll Graph::Size(ll v)
{
	return adj[v].size();
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll n, m, k, i, n1, n2, size = 0;
	cin >> n >> m >> k;
	vector<ll> lessArr;
	Graph nobles(n);
	for(i = 0; i < m; i++)
	{
		cin >> n1 >> n2;
		n1--; n2--;
		nobles.addEdge(n1, n2);
	}
	bool del[n], pres[n];
	ll degree[n];
	for(i = 0; i < n; i++)
	{
		del[i] = false;
		pres[i] = false;
		degree[i] = nobles.Size(i);
		if(nobles.Size(i) < k)
		{
			lessArr.push_back(i);
			pres[i] = true;
		}
	}
	for(i = 0; i < lessArr.size(); i++)
	{
		del[lessArr[i]] = true;
		pres[lessArr[i]] = false;
		for(list<int>::iterator it = nobles.adj[lessArr[i]].begin(); it != nobles.adj[lessArr[i]].end(); it++)
		{
			if(!(pres[*it]) && !(del[*it]))
			{
				degree[*it]--;
				if(degree[*it] < k)
				{
					lessArr.push_back(*it);
					pres[*it] = true;
				}
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		if(!del[i])
		{
			size++;
		}
	}
	if(size > 0)
	{
		cout << "YES" << endl << size;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
