/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
typedef struct
{
        ll x;
        ll y;
} pt;
 
int main()
{       
        ios_base::sync_with_stdio(false); cin.tie(0);
        //freopen("test.in", "r", stdin);
        ll r, c, i, j;
        bool isPossible = false;
        cin >> r >> c;
        char maze[r][c], k;
        pt mouse, dosa, current, neighbour, nll, came;
        pt came_from[r][c];
        queue<pt> frontier;
        map<pair<ll, ll>, bool> isVisited;
        for(i = 0; i < r; i++)
        {
                for(j = 0; j < c; j++)
                {
                        cin >> maze[i][j];
                        k = maze[i][j];
                        if(maze[i][j] == 'M')
                        {
                                mouse.x = i;
                                mouse.y = j;
                        }
                        if(maze[i][j] == 'D')
                        {
                                dosa.x = i;
                                dosa.y = j;
                        }
                }
        }
        nll.x = -1, nll.y = -1;
        frontier.push(mouse);
        came_from[mouse.x][mouse.y] = nll;
        while(!frontier.empty())
        {
                current = frontier.front();
                frontier.pop();
                if(current.x == dosa.x && current.y == dosa.y)
                {
                        isPossible = true;
                        break;
                }
                came = came_from[current.x][current.y];
                for(i = 0; i < 4; i++)
                {
                        switch(i)
                        {
                                case 0:
                                        neighbour.x = current.x - 1;
                                        neighbour.y = current.y;
                                        break;
                                case 1:
                                        neighbour.x = current.x;
                                        neighbour.y = current.y+1;
                                        break;
                                case 2:
                                        neighbour.x = current.x + 1;
                                        neighbour.y = current.y;
                                        break;
                                case 3:
                                        neighbour.x = current.x;
                                        neighbour.y = current.y-1;
                                        break;
                        }
                        if(neighbour.x < 0)
                        {
                                neighbour.x = r-1;
                        }
                        if(neighbour.y < 0)
                        {
                                neighbour.y = c-1;
                        }
                        if(neighbour.x == r)
                        {
                                neighbour.x = 0;
                        }
                        if(neighbour.y == c)
                        {
                                neighbour.y = 0;
                        }
                        if(maze[neighbour.x][neighbour.y] != '#' && !(neighbour.x == came_from[current.x][current.y].x && neighbour.y == came_from[current.x][current.y].y) && isVisited[make_pair(neighbour.x, neighbour.y)] == false)
                        {
                                came_from[neighbour.x][neighbour.y] = current;
                                isVisited[make_pair(neighbour.x, neighbour.y)] = true;
                                frontier.push(neighbour);
                        }
                }
        }
        if(isPossible)
        {
                cout << "YES" << endl;
                current = came_from[current.x][current.y];
                while(current.x != -1 && current.y != -1)
                {
                        maze[current.x][current.y] = 'x';
                        current = came_from[current.x][current.y];
                }
                maze[mouse.x][mouse.y] = 'M';
                for(i = 0; i < r; i++)
                {
                        for(j = 0; j < c; j++)
                        {
                                cout << maze[i][j];
                        }
                        cout << endl;
                }
        }
        else
        {
                cout << "NO";
        }
        return 0;
}
