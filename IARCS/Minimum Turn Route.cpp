/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1001
#define mp make_pair
char discs[M][M][4];
map<pair<ll, ll>, pair<ll, ll> > came_from;
map<pair<ll, ll>, ll> minPenalty;
map<pair<ll, ll>, bool> visited;
class comp
{
public:
  bool operator() (const pair<pair<ll, ll>, ll>& lhs, const pair<pair<ll, ll>, ll>&rhs) const
  {
    return (lhs.second > rhs.second);
  }
};

priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll> >, comp> frontier;
ll calcPenalty(char disc1[], char disc2[], ll dir)
{
	ll counter = 0, dirOther = dir - 2;
	if(dirOther < 0)
	{
		dirOther += 4;
	}
	while(disc1[dir] != disc2[dirOther])
	{
		dir--;
		counter++;
		if(dir < 0)
		{
			dir = 3;
		}
	}
	return counter;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("8.in", "r", stdin);
	ll m, n, i, j, k, dir, cost;
	cin >> m >> n;
	pair<pair<ll, ll>, ll> curr;
	pair<ll, ll> currLoc, nextLoc, destination;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < 4; k++)
			{
				cin >> discs[i][j][k];
			}
			minPenalty[mp(i, j)] = INT_MAX;
		}
	}
	destination = mp(m-1, n-1);
	frontier.push(mp(mp(0, 0), 0));
	came_from[mp(0, 0)] = mp(-1, -1);
	ll penalty;
	while(!frontier.empty())
	{
		curr = frontier.top();
		currLoc = curr.first;
		penalty = curr.second;
		frontier.pop();
		if(currLoc.first == m-1 && currLoc.second == n-1)
		{
			break;
		}
		for(i = 0; i < 4; i++)
		{
			dir = i;
			switch(i)
			{
				case 0:
					nextLoc.first = currLoc.first - 1;
					nextLoc.second = currLoc.second;
					break;
				case 1:
					nextLoc.first = currLoc.first;
					nextLoc.second = currLoc.second + 1;
					break;
				case 2:
					nextLoc.first = currLoc.first + 1;
					nextLoc.second = currLoc.second;
					break;
				case 3:
					nextLoc.first = currLoc.first;
					nextLoc.second = currLoc.second - 1;
					break;
			}
			if(nextLoc.first >= 0 && nextLoc.first < m && nextLoc.second >= 0 && nextLoc.second < n && came_from[currLoc] != nextLoc && came_from[came_from[currLoc]] != nextLoc)
			{
				cost = calcPenalty(discs[currLoc.first][currLoc.second], discs[nextLoc.first][nextLoc.second], dir) + penalty;
				if(cost < minPenalty[nextLoc])
				{
					frontier.push(mp(nextLoc, cost));
					minPenalty[nextLoc] = cost;
					came_from[nextLoc] = currLoc;
				}
			}
		}
	}
	cout << penalty;
	return 0;
}
