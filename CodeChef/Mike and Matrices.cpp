#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
ll matrix[501][501];
pii arr[250001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, m, i, j, l, e1 = 0, e2 = 0;
	bool v1 = true, v2 = true;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cin >> l;
	for(i = 1; i <= l; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	for(i = 1; i <= l; i++)
	{
		if(arr[i].first <= n && arr[i].second <= m && v1)
		{
			e1 += matrix[arr[i].first][arr[i].second];
		}
		else
		{
			e1 = -1;
			v1 = false;
		}
		if(arr[i].second <= n && arr[i].first <= m && v2)
		{
			e2 += matrix[arr[i].second][arr[i].first];
		}
		else
		{
			e2 = -1;
			v2 = false;
		}
	}
	cout << max(e1, e2) << endl;
	return 0;
}
