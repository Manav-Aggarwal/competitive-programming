/*Manav Aggarwal
36110
Problem: Brackets*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1111
#define INF 1111111
ll maxVal = -INF;
void solve(vector<ll> seq, ll v[], ll b[], ll n, ll k, ll ind, ll val)
{
	if(ind > n)
	{
		stack<ll> frontier;
		for(ll i = 0; i < seq.size(); i++)
		{
			if(frontier.empty())
			{
				frontier.push(seq[i]);
			}
			else
			{
				if(frontier.top() + k == seq[i])
				{
					frontier.pop();
				}
				else
					frontier.push(seq[i]);
			}
		}
		if(frontier.empty())
		{
			/*for(ll i = 0; i < seq.size(); i++)
			{
				cout << seq[i] << " ";
			}
			cout << endl;*/
			maxVal = max(maxVal, val);
		}
	}
	else
	{
		solve(seq, v, b, n, k, ind+1, val);
		seq.push_back(b[ind]);
		val += v[ind];
		solve(seq, v, b, n, k, ind+1, val);
	}
}
ll v[MAX], b[MAX];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k, i;
	cin >> n >> k;
	for(i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for(i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	vector<ll> seq;
	seq.clear();
	solve(seq, v, b, n, k, 1, 0);
	cout << maxVal << endl;
	return 0;
}
