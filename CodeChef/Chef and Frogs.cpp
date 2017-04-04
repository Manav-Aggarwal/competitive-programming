/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<ll, ll>
bool wayToSort(pi i, pi j) { return i.first < j.first; }
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k, p, i, j;
	cin >> n >> k >> p;
	pi frogs[n];
	ll MaxInd[n];
	for(i = 0; i < n; i++)
	{
		cin >> frogs[i].first;
		frogs[i].second = i;
		MaxInd[i] = i;
	}
	sort(frogs, frogs + n, wayToSort);
	for(i = 0; i < n; i++)
	{
		j = i + 1;
		while(j < n && frogs[j].first - frogs[j-1].first <= k)
		{
			MaxInd[frogs[j].second] = MaxInd[frogs[i].second];
			j++;
		}
		i = j-1;
	}
	for(i = 0; i < p; i++)
	{
		ll f1, f2;
		cin >> f1 >> f2;
		f1--; f2--;
		if(MaxInd[f1] == MaxInd[f2])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
