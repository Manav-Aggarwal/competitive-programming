#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
map <ll, pii> css[1000001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, id, attr, val, prior;
	cin >> n >> m;
	while(n--)
	{
		cin >> id >> attr >> val >> prior;
		if(css[id].find(attr) == css[id].end())
		{
			css[id][attr] = pii(val, prior);
		}
		else
		{
			pii curr = css[id][attr];
			if(curr.second <= prior)
			{
				css[id][attr] = pii(val, prior);
			}
		}
	}
	while(m--)
	{
		cin >> id >> attr;
		cout << css[id][attr].first << endl;
	}
	return 0;
}
