/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define mp make_pair
#define mpp(cost, x, y) mp(cost, mp(x, y))
#define x second.first
#define y second.second
#define cost first
#define INF 999999999999999
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		ll w, h, i, j;
		cin >> w >> h;
		if(!w && !h)
			break;
		char grid[h][w];
		pii start, destination, came_from[h][w];
		ll cost[h][w], currCost, currX, currY, nextX, nextY, nextCost, ans;
		bool visited[h][w], flag = false;
		for(i = 0; i < h; i++)
		{
			for(j = 0; j < w; j++)
			{
				cin >> grid[i][j];
				if(grid[i][j] == 'S')
					start = mp(i, j);
				if(grid[i][j] == 'D')
					destination = mp(i, j);
			}
		}
		priority_queue<piii, vector<piii>, greater<piii> > frontier;
		cost[start.first][start.second] = 0;
		frontier.push(mpp(0, start.first, start.second));
		came_from[start.first][start.second] = mp(-1, -1);
		memset(visited, false, sizeof(visited));
		while(!frontier.empty())
		{
			if(flag)
				break;
			currCost = frontier.top().cost;
			currX = frontier.top().x; currY = frontier.top().y;
			frontier.pop();
			if(visited[currX][currY])
				continue;
			visited[currX][currY] = true;
			for(i = 0; i < 4; i++)
			{
				switch(i)
				{
					case 0:
						nextX = currX + 1;
						nextY= currY;
						break;
					case 1:
						nextX = currX;
						nextY = currY + 1;
						break;
					case 2:
						nextX = currX - 1;
						nextY = currY;
						break;
					case 3:
						nextX = currX;
						nextY = currY - 1;
						break;
				}
				if(nextX >= 0 && nextX < h && nextY >= 0 && nextY < w && grid[nextX][nextY] != 'X' && !(nextX == came_from[currX][currY].first && nextY == came_from[currX][currY].second))
				{
					if(grid[nextX][nextY] == 'D')
					{
						ans = currCost;
						flag = true;
						break;
					}
					nextCost = currCost + grid[nextX][nextY] - '0';
					came_from[nextX][nextY] = mp(currX, currY);
					frontier.push(mpp(nextCost, nextX, nextY));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
