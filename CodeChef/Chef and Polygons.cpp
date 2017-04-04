/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool wayToSort(pair<ll, ll> a, pair<ll, ll> b){return a.first < b.first;}
const ll limit = 100000;
ll ranks[limit+1];
vector<pair<ll, ll> > polygon;
vector<pair<double, ll> > areas;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll m, n, i, j, x, y;
		double area;
		polygon.clear(); 
		areas.clear();
		cin >> n;
		for(i = 0; i < n; i++)
		{
			cin >> m;
			for(j = 0; j < m; j++)
			{
				cin >> x;
				cin >> y;
				polygon.push_back(make_pair(x, y));
			}
			area = 0.0;
			for(j = 0; j < m-1; j++)
			{
				area += (polygon[i].first*polygon[i+1].second) - (polygon[i].second*polygon[i+1].first);
			}
			area += polygon[m-1].first*polygon[0].second - polygon[m-1].second*polygon[0].first;
			area = ((double)area)/2.0;
			if(area < 0)
			{
				area = -area;
			}
			areas.push_back(make_pair(area, i));
			polygon.clear();
		}
		sort(areas.begin(), areas.end(), wayToSort);
		for(i = 0; i < n; i++)
		{
			ranks[areas[i].second] = i;
		}
		for(i = 0; i < n; i++)
		{
			cout << ranks[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
