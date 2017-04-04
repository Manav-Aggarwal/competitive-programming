#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, leadguy, lead = 0, add1 = 0, add2 = 0;
	cin >> n;
	for(long long int i = 0; i < n; i++)
	{
		long long int p1, p2;
		cin >> p1 >> p2;
		p1 += add1; p2+= add2;
		if(p1 > p2 && p1 - p2 > lead)
		{
			leadguy = 1;
			lead = p1 - p2;
		}
		else if (p2 > p1 && p2 - p1 > lead)
		{
			leadguy = 2;
			lead = p2 - p1;
		}
		add1 = p1; add2 = p2;
	}
	cout << leadguy << " " << lead;
	return 0;
}
