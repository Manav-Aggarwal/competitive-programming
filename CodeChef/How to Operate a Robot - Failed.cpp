/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair

/*This is some amazing code*/
class custComp
{
public:
  bool operator() (const pair<pair<string, pair<ll, ll> >, map<pair<ll, ll>, bool> >& lhs, const pair<pair<string, pair<ll, ll> >, map<pair<ll, ll>, bool> >&rhs) const
  {
	return (lhs.first.first.length() > rhs.first.first.length());
  }
};

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll sideLength, i, j, numberOpen = 0;
		cin >> sideLength;
		char maze[sideLength][sideLength], dir;
		pair<ll, ll> curr = mp(0, 0), next;
		map<pair<ll, ll>, bool> visited;
		visited[curr] = true;
		pair<pair<string, pair<ll, ll> >, map<pair<ll, ll>, bool> > temp;
		string seq;
		for(i = 0; i < sideLength; i++)
		{
			for(j = 0; j < sideLength; j++)
			{
				cin >> maze[i][j];
				if(maze[i][j] == '.')
				{
					numberOpen++;
				}
			}
		}
		priority_queue<pair<pair<string, pair<ll, ll> >, map<pair<ll, ll>, bool> >, vector<pair<pair<string, pair<ll, ll> >, map<pair<ll, ll>, bool> > >, custComp > frontier;
		frontier.push(mp(mp("", mp(0, 0)), visited));
		while(!frontier.empty())
		{
			temp = frontier.top();
			frontier.pop();
			curr = temp.first.second;
			seq = temp.first.first;
			if(seq.length() > sideLength*(sideLength+7) || (seq.length() >= 4 && seq[seq.length()-1] == seq[seq.length()-2] && seq[seq.length()-2] == seq[seq.length()-3] && seq[seq.length()-3] == seq[seq.length()-4]))
			{
				continue;
			}
			if(temp.second.size() >= numberOpen)
			{
				break;
			}
			for(i = 0; i < 4; i++)
			{
				seq = temp.first.first;
				visited = temp.second;
				switch(i)
				{
					case 0:
						next.first = curr.first;
						next.second = curr.second+1;
						dir = 'R';
						break;
					case 1:
						next.first = curr.first + 1;
						next.second = curr.second;
						dir = 'D';
						break;
					case 2:
						next.first = curr.first;
						next.second = curr.second - 1;
						dir = 'L';
						break;
					case 3:
						next.first = curr.first - 1;
						next.second = curr.second;
						dir = 'U';
						break;
				}
				if(next.first >= 0 && next.first < sideLength && next.second >= 0 && next.second < sideLength && maze[next.first][next.second] == '.')
				{
					seq += dir; 
					visited[next] = true;
					frontier.push(mp(mp(seq, next), visited));
				}
			}
		}
		cout << seq << endl;
	}
	return 0;
}
