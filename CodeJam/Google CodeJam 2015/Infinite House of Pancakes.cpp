/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-Output-Small.out", "w", stdout);
	int t, cases;
	cin >> t;
	cases = t;
	while(t--)
	{
		int d, minutes = 0, maximum = 0;
		cin >> d;
		vector <int> diners;
		for(int i = 0; i < d; i++)
		{
			int k;
			cin >> k;
			diners.push_back(k);
		}
		for(int i = 0; i < d; i++)
		{
			if(diners[i] > 3)
			{
				minutes++;
				diners[i] = ceil(diners[i]/2);
			}
			maximum = max(minutes, diners[i]);
		}
		minutes += maximum;
		cout << "Case #" << cases - t << ": " << minutes << endl;
	}
	return 0;
}
