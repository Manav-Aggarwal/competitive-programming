/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool comp(pair<ll, ll> num1, pair<ll, ll> num2)
{
	return num1.first > num2.first;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("1.in", "r", stdin);
	ll n, i, rating, nextI, numPaired = 0;
	cin >> n;
	pair<ll, ll> siruseri[n], navalur[n];
	bool occupiedS[n], occupiedN[n];
	vector<pair<ll, ll> > pairings;
	for(i = 0; i < n; i++)
	{
		occupiedS[i] = false;
		cin >> rating;
		siruseri[i] = make_pair(rating, i+1);
	}
	for(i = 0; i < n; i++)
	{
		occupiedN[i] = false;
		cin >> rating;
		navalur[i] = make_pair(rating, i+1);
	}
	sort(siruseri, siruseri+n, comp);
	sort(navalur, navalur+n, comp);
	nextI = 0;
	for(i = 0; i < n; i++)
	{
		while((nextI < n && siruseri[i].first < navalur[nextI].first) || occupiedN[nextI])
		{
			nextI++;
		}
		if(nextI < n)
		{
			occupiedS[i] = true;
			occupiedN[nextI] = true;
			pairings.push_back(make_pair(siruseri[i].second, navalur[nextI].second));
			numPaired++;
		}
	}
	nextI = 0;
	for(i = 0; i < n; i++)
	{
		if(!occupiedN[i])
		{
			while(nextI < n && occupiedS[nextI])
			{
				nextI--;
			}
			if(nextI < n)
			{
				occupiedN[i] = true;
				occupiedS[nextI] = true;
				pairings.push_back(make_pair(siruseri[nextI].second, navalur[i].second));
			}
		}
	}
	cout << numPaired << endl;
	sort(pairings.begin(), pairings.end());
	for(i = 0; i < pairings.size(); i++)
	{
		cout << pairings[i].second << endl;
	}
	return 0;
}
