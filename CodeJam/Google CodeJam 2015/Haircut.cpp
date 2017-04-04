/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll B, N, i, max_time = 0, max_index = -1, temp;
		cin >> B >> N;
		vector<ll> M;
		vector<ll> pattern;
		M.push_back(0);
		for(i = 1; i <= B; i++)
		{
			cin >> temp;
			M.push_back(temp);
			if(M[i] > max_time)
			{
				max_time = M[i];
				max_index = i;
			}
		}
		vector<ll> sorted;
		sorted = M;
		sort(sorted.begin(), sorted.end());
		for(i = 1;i<=B; i++)
		{
			pattern.push_back(i);
		}
		
	}
	return 0;
}
