/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool wayToSort(pair<ll, ll> a, pair<ll, ll> b){return a.second < b.second;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, dur, start, end, current, next, count;
	cin >> n;
	pair<ll, ll> events[n];
	for(i = 0; i < n; i++)
	{
		cin >> start;
		cin >> dur;
		end = start + dur;
		events[i] = make_pair(start, end);
	}
	sort(events, events+n, wayToSort);
	current = events[0].second;
	count = 1;
	for(i = 1; i < n; i++)
	{
		if(events[i].first > current)
		{
			current = events[i].second;
			count++;
		}
	}
	cout << count;
	return 0;
}
