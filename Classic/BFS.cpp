#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void BFS(vector <int> edges[], v)
{
	set <int> visited;
	queue <int> q;
	q.push(v);
	visited.insert(v);
	while(q.size() != 0)
	{
		v = q.front();
		q.pop();
		for(int i = 0; i < edges[v].size(); i++)
		{
			if(visited.count(edges[v][i]) == 0)
			{
				q.push(edges[v][i]);
				visited.push(edges[v][i]);
			}
		}
	}
	
}
