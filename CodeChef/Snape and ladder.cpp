#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		double B, LS, min , max;
		cin >> B >> LS;
		min = sqrt((LS*LS) - (B*B));
		max = sqrt((LS*LS) + (B*B));
		
		cout << fixed << min << " " << max << endl;
	}
	return 0;
}
