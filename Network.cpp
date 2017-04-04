#include "network.h"
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> graph[1001];
int getP(int a, int b)
{
	return ping(a, b) + 1;
}
void findRoute (int N, int a, int b)
{
    int dist, i, k, d, curr;
    for(i = 1; i <= N; i++)
    {
    	if(i == b)
    	{
    		k = getP(a, i);
    		dist = k;
    		graph[k].push_back(i);
    		if(dist == 1)
    		{
    			travelTo(b);
    			curr = b;
			}
		}
		else if(i != a)
		{
			k = getP(a, i);
			graph[k].push_back(i);
			if(k == 1)
			{
				d = getP(i, b);
				if(d + 1 == dist)
				{
					travelTo(i);
					curr = i;
				}
			}
		}
	}
	for(k = 2; k < dist; k++)
	{
		bool flag = true;
		for(i = 0; i < graph[k].size(); i++)
		{
			d = getP(graph[k][i], b);
			if(d + k == dist)
			{
				d = getP(curr, graph[k][i]);
				if(d == 1)
				{
					travelTo(graph[k][i]);
					curr = graph[k][i];
					flag = false;
					continue;
				}
			}
		}
	}
	if(curr != b)
		travelTo(b);
}
