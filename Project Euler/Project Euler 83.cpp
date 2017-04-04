/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii make_pair

ll stringToNum(string str)
{
	ll i, num = 0;
	for(i = 0; i < str.length(); i++)
	{
		num += (ll)str[i] - '0';
		num*= 10;
	}
	return num/10;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream file("matrix.txt");
	stringstream buffer;
	buffer << file.rdbuf();
	string test = buffer.str(), tmp = "";
	vector<vector<ll> > grid; 
	vector<ll> line;
	ll i, j, minSum = INT_MAX, newI, newJ, newCost;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == ',')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
		}	
		else if(test[i] == '\n')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
			grid.push_back(line);
			line.clear();
		}
		else
		{
			tmp += test[i];
		}
	}
	map<pair<ll, ll>, ll> cost_so_far;
	map<pair<ll, ll>, bool> visited;
	map<pair<ll, ll>, pair<ll, ll> > came_from;
	priority_queue<pair<ll, pair<ll, ll> >, vector<pair<ll, pair<ll, ll> > >, greater<pair<ll, pair<ll, ll> > > > frontier;
	frontier.push(pii(grid[0][0], pii(0, 0)));
	came_from[pii(0, 0)] = pii(-1, -1);
	cost_so_far[pii(0, 0)] = grid[0][0];
	visited[pii(0, 0)] = true;
	while(!frontier.empty())
	{
		pair<ll, pair<ll, ll> > current = frontier.top();
		visited[current.second] = true;
		frontier.pop(); 
		if(current.second.first == grid.size()-1 && current.second.first == current.second.second)
		{
			break;
		}
		for(i = 0; i < 4; i++)
		{
			switch(i)
			{
				case 0:
					newI = current.second.first-1;
					newJ = current.second.second;
					break;
				case 1:
					newI = current.second.first;
					newJ = current.second.second+1;
					break;
				case 2:
					newI = current.second.first+1;
					newJ = current.second.second;
					break;
				case 3:
					newI = current.second.first;
					newJ = current.second.second - 1;
					break;
			}
			if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid.size())
			{
				newCost = cost_so_far[current.second] + grid[newI][newJ];
				if((cost_so_far[pii(newI, newJ)] == 0 || newCost < cost_so_far[pii(newI, newJ)]) && !visited[pii(newI, newJ)])
				{
					cost_so_far[pii(newI, newJ)] = newCost;
					frontier.push(pii(newCost, pii(newI, newJ)));
					came_from[pii(newI, newJ)] = current.second;
				}
			}
		}
	}
	cout << cost_so_far[pii(grid.size()-1, grid.size()-1)];
	return 0;
}
