#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<ll, ll>
bool wayToSort(pi a, pi b) { return a.second < b.second;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		vector<pi> v;
		ll N, a , b, i;
		cin >> N;
		for(i = 0; i < N; i++)
		{
			cin >> a >> b;
			v.push_back(pi(a,b));
		}
		ll prev = -1, cnt = 0;
		sort(v.begin(), v.end(), wayToSort);
		for(i = 0; i < N; i++)
		{
			if(v[i].first > prev)
			{
				cnt++;
				prev = v[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
