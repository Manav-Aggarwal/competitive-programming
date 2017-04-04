/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("D-large.in", "r", stdin);
	freopen("Ominous-Omino-Output-Large.out", "w", stdout);
	ll t, cases;
	cin >> t;
	cases = t;
	while(t--)
	{
		ll x, r, c, d;
		string winner;
		cin >> x >> r >> c;
		d = floor(x/2);
		if(x == 2)
		{
			if((r*c) % 2 == 0)
			{
				winner = "GABRIEL";
			}
			else
			{
				winner = "RICHARD";
			}
		}
		else if((r*c) % x != 0)
		{
			winner = "RICHARD";
		}
		else if(r <= d || c <= d)
		{
			winner = "RICHARD"; 
		}
		else
		{
			winner = "GABRIEL";
		}
		
		cout << "Case #" << (cases - t) << ": " << winner << endl;
	}
	return 0;
}
