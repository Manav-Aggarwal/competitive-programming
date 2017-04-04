#include <bits/stdc++.h>
using namespace std;
int adj[301][301][2];
int graph[301][301];
vector<int> critints;
int main()
{
	//freopen("10.in", "r", stdin);
	int N, M, k = 1;
	cin >> N >> M ;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			graph[i][j] = 0;
		}
	}
	for(int i = 0; i < M;i++)
	{
		int i1, i2;
		cin >> i1 >> i2;
		graph[i1][i2] = 1;
		graph[i2][i1] = 1;
	}
	for(int i = 1 ; i <= N; i++)
	{
		int c = 0;
		for(int j = 1; j <= N; j++)
		{
			if(graph[i][j] == 1)
			{
				adj[i][c][0] = j;
				c++;
			}
		}
		adj[i][0][1] = c;
		
	}
	set <int> visited;
	for(int k = 1; k <= N; k++)
	{
		int d = 0, v = 0;
		visited.clear();
		stack <int> S;
		d = (k == 1) ? 2 : 1 ;
		S.push(d); 
		while(!S.empty())
		{
			v = S.top();
			S.pop();
			if(visited.count(v) == 0)
			{
				visited.insert(v);
				for(int i = 0; i < adj[v][0][1]; i++)
				{
					if (adj[v][i][0] != k)
					{
						S.push(adj[v][i][0]);
					}
				}
			}
		}
		if(visited.size() != N-1)
		{
			critints.push_back(k);
		}
	}
	cout << critints.size() << endl;
	for(int i = 0; i < critints.size(); i++)
	{
		cout << critints[i]<< endl;
	}
}
