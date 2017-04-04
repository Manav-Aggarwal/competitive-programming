/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair

/*This is some amazing code*/

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll sideLength, i, j;
		cin >> sideLength;
		char maze[sideLength][sideLength];
		map<char, pair<ll, ll> > shift;
		shift['R'] = mp(1, 0);
		shift['D'] = mp(0, 1);
		shift['L'] = mp(-1, 0);
		shift['U'] = mp(0, -1); 
		pair<ll, ll> curr = mp(0, 0), next, change;
		string seq = "", pattern1 = "DRUR", pattern2 = "DLUL", pattern3 = "LDR", pattern4 = "RDL", pattern5 = "LDDR", pattern6 = "RDDL", currPattern;
		map<pair<ll, ll>, bool> visited;
		for(i = 0; i < sideLength; i++)
		{
			for(j = 0; j < sideLength; j++)
			{
				cin >> maze[i][j];
			}
		}
		visited[curr] = true;
		while(visited.size() != sideLength*sideLength)
		{
			i = 0;
			while(true)
			{
				change = shift[pattern1[i]];
				curr.first += change.first;
				curr.second += change.second;
				if(curr.first >= sideLength || curr.first < 0 || curr.second >= sideLength || curr.second < 0)
				{
					curr.first -= change.first;
					curr.second -= change.second;
					if(i == 0)
					{
						i = 4;
					}
					if(pattern1[i-1] == 'D')
					{
						currPattern = pattern3;
					}
					else //the character is U
					{
						currPattern = pattern5;
					}
					break;
				}
				visited[curr] = true;
				seq += pattern1[i++];
				if(i == 4)
				{
					i = 0;
				}
			}
			if(visited.size() >= sideLength*sideLength)
			{
				break;
			}
			if(sideLength - curr.second != 2)
			{
				for(i = 0; i < currPattern.size(); i++)
				{
					change = shift[currPattern[i]];
					curr.first += change.first;
					curr.second += change.second;
					if(curr.first >= sideLength || curr.first < 0 || curr.second >= sideLength || curr.second < 0)
					{
						curr.first -= change.first;
						curr.second -= change.second;
						if(i == 0)
						{
							i = 4;
						}
						if(pattern1[i-1] == 'D')
						{
							currPattern = pattern3;
						}
						else //the character is U
						{
							currPattern = pattern5;
						}
						break;
					}
					visited[curr] = true;
					seq += currPattern[i];
				}
			}
			
			if(visited.size() >= sideLength*sideLength)
			{
				break;
			}
			i = 0;
			while(true)
			{
				change = shift[pattern2[i]];
				curr.first += change.first;
				curr.second += change.second;
				if(curr.first >= sideLength || curr.first < 0 || curr.second >= sideLength || curr.second < 0)
				{
					curr.first -= change.first;
					curr.second -= change.second;
					if(i == 0)
					{
						i = 4;
					}
					if(pattern1[i-1] == 'D')
					{
						currPattern = pattern4;
					}
					else //the character is U
					{
						currPattern = pattern6;
					}
					break;
				}
				visited[curr] = true;
				seq += pattern2[i++];
				if(i == 4)
				{
					i = 0;
				}
			}
			if(visited.size() >= sideLength*sideLength)
			{
				break;
			}
			if(sideLength - curr.second != 2)
			{
				for(i = 0; i < currPattern.size(); i++)
				{
					change = shift[currPattern[i]];
					curr.first += change.first;
					curr.second += change.second;
					if(curr.first >= sideLength || curr.first < 0 || curr.second >= sideLength || curr.second < 0)
					{
						curr.first -= change.first;
						curr.second -= change.second;
						if(i == 0)
						{
							i = 4;
						}
						if(pattern1[i-1] == 'D')
						{
							currPattern = pattern3;
						}
						else //the character is U
						{
							currPattern = pattern5;
						}
						break;
					}
					visited[curr] = true;
					seq += currPattern[i];
				}
			}
			
		}
		cout << seq << endl;
	}
	return 0;
}
