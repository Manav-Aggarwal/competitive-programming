/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, next, first, j;
	cin >> n;
	ll arr[n];
	map<ll, bool> visited;
	vector<ll> cycle;
	vector<vector<ll> > cycles;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	visited[1] = true;
	first = 1;
	cycle.push_back(1);
	next = arr[0];
	cycle.push_back(next);
	while(visited.size() != n)
	{
		while(next != first)
		{
			visited[next] = true;
			next = arr[next-1];
			cycle.push_back(next);
		}
		cycles.push_back(cycle);
		cycle.clear();
		for(i = 2; i <= n; i++)
		{
			if(!visited[i])
			{
				first = i;
				visited[first] = true;
				cycle.push_back(first);
				next = arr[first-1];
				cycle.push_back(next);
				break;
			}
		}
	}
	if(cycle.size() != 0)
	{
		cycles.push_back(cycle);
	}
	cout << cycles.size() << endl;
	for(i = 0; i < cycles.size(); i++)
	{
		for(j = 0; j < cycles[i].size(); j++)
		{
			cout << cycles[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
