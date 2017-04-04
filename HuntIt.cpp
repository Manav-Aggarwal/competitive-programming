/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define INF 999999999
ll dist(string k1, string k2)
{
	ll i, dis = 0;
	for(i = 0; i < 4; i++)
	{
		dis += abs(k1[i] - k2[i]);
	}
	return dis;
}
ll findMin(ll keys[], ll n, bool mst[], string curr)
{
	ll minNum = INF, minInd, i;
	for(i = 1; i <= n; i++)
	{
		if(keys[i] < minNum && !mst[i] && keys[i] != inf)
		{
			minInd = i;
			minNum = keys[i];
		}
	}
	return minInd;
}
int main() 
{
    ll t;
    cin >> t;
    while(t--)
    {
    	ll n, i, j, moves = 0;
    	set<ll>::iterator k;
		cin >> n;
		string keys[n];
		vector<string> visited;
		set<ll> notVisited;
		map<string, bool> marked;
		for(i = 0; i < n; i++)
		{
			cin >> keys[i];
			notVisited.insert(i);
		}
		visited.push_back("0000");
		marked["0000"] = true;
		while(nMarked < z-1)
		{
			ind = findMin(keys, z, mst);
			mst[ind] = true;
			nMarked++;
			for(i = 1; i <= z; i++)
			{
				if(!mst[i] && adjM[ind][i] < keys[i])
				{
					prnt[i] = ind; keys[i] = adjM[ind][i];
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			ll minN = INF, minI = i;
			for(j = 0; j < visited.size(); j++)
			{
				
				for(k = notVisited.begin(); k != notVisited.end(); k++)
				{
					if(minN > dist(visited[j], keys[(*k)]))
					{
						minN = dist(visited[j], keys[(*k)]);
						minI = (*k);
					}
				}
			}
			visited.push_back(keys[minI]);
			marked[keys[minI]] = true;
			notVisited.erase(minI);
			moves += minN;
		}
		cout << moves << endl;
	}
    return 0;
}
