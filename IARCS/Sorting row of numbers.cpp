/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, num;
	cin >> n;
	vector<vector<ll> > rows;
	vector<ll> row;
	for(i = 0; i < n; i++)
	{
		while(true)
		{
			cin >> num;
			if(num != -1)
			{
				row.push_back(num);
			}
			else
			{
				rows.push_back(row);
				row.clear();
				break;
			}
		}
	}
	sort(rows.begin(), rows.end());
	for(i = 0; i < rows.size(); i++)
	{
		for(j = 0; j < rows[i].size(); j++)
		{
			cout << rows[i][j] << " "; 
		}
		cout << endl;
	}
	return 0;
}
