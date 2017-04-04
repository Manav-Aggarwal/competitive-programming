/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("01.out", "w", stdout);
	int t, cases;
	cin >> t;
	cases = t;
	while(t--)
	{
		ll R, W, moves;
		double C;
		cin >> R >> C >> W;
		if(W == C || W == 1)
		{
			moves = C;
		}
		else
		{
			ll c = ceil(C/2);
			if(W <= c)
			{
				moves = c + 1;
			}
			else
			{
				moves = W + 1;
			}
		}
		cout << "Case #" << cases - t << ": " << moves << endl;
	}
	return 0;
}
