/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool comp(ll a, ll b)
{
	return a > b;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll m, n, i, j, h, v, cost = 0;
		cin >> m >> n;
		ll rows[m], columns[n];
		for(i = 1; i < m; i++)
		{
			cin >> rows[i];
		}
		for(i = 1; i < n; i++)
		{
			cin >> columns[i];
		}
		sort(rows+1, rows + m, comp);
		sort(columns+1, columns + n, comp);
		i = j = h = v = 1;
		while(i < m && j < n)
		{
			if(rows[i] > columns[j])
			{
				cost += rows[i]*v;	
				i++;
				h++;
			}
			else
			{
				cost += columns[j]*h;
				j++;
				v++;
			}
		}
		if(i < m)
		{
			while(i < m)
			{
				cost += rows[i]*v;
				i++;
			}	
		}
		else
		{
			while(j < n)
			{
				cost += columns[j]*h;
				j++;
			}	
		}
		
		cout << cost << endl;
	}
	return 0;
}
