/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, a, b, maxCnt = 0, tmp, cnt, maxP, limit = 1000;
	for(i = 12; i <= limit; i+=2)
	{
		cnt = 0;
		for(a = 2; a < i/3; a++)
		{
			if(i*(i - 2*a) % (2*(i-a)) == 0)
			{
				cnt++;
			}
		}
		if(maxCnt < cnt)
		{
			maxCnt = cnt;
			maxP = i;
		}
	}
	cout << maxP;
	return 0;
}
