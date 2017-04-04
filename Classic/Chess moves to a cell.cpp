/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair
#define pci pair<char, ll>
bool isValid(pci p)
{
	if(p.first >= 'a' && p.first <= 'h' && p.second >= 1 && p.second <= 8)
	{
		return true;
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	char a;
	ll b;
	cin >> a >> b;
	map<pci, bool> visited;
	map<pci, pci > came_from;
	queue<pci > frontier;
	frontier.push(mp('a', 1));
	pci curr;
	while(!frontier.empty())
	{
		curr = frontier.front();
		frontier.pop();
		visited[curr] = true;
		if(curr.first == a && curr.second == b)
		{
			break;
		}
		pci h2fv1l = mp((char)(curr.first - 1), curr.second + 2), h2fv1r = mp((char)(curr.first + 1), curr.second + 2), h2bv1l = mp((char)(curr.first - 1), curr.second - 2);
		pci h2bv1r = mp((char)(curr.first + 1), curr.second - 2), h1fv2l = mp((char)(curr.first - 2), curr.second + 1), h1fv2r = mp((char)(curr.first + 2), curr.second + 1);
		pci h1bv2l = mp((char)(curr.first - 2), curr.second - 1), h1bv2r = mp((char)(curr.first + 2), curr.second - 1);
		vector<pci > pairs;
		pairs.push_back(h2fv1l), pairs.push_back(h2fv1r), pairs.push_back(h2bv1l), pairs.push_back(h2bv1r), pairs.push_back(h1fv2l), pairs.push_back(h1fv2r), pairs.push_back(h1bv2l), pairs.push_back(h1bv2r); 
		for(ll i = 0; i < pairs.size(); i++)
		{
			if((!visited[pairs[i]]) && isValid(pairs[i]))
			{
				came_from[pairs[i]] = curr;
				frontier.push(pairs[i]);
				visited[pairs[i]] = true;
			}
		}
	}
	vector<pci > path;
	while(!(curr.first == 'a' && curr.second == 1))
	{
		path.push_back(curr);
		curr = came_from[curr];
	}
	for(ll i = path.size()-1; i >= 0; i--)
	{
		cout << path[i].first << path[i].second << " ";
	}
	return 0;
} 
