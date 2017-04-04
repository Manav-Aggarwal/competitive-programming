/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll limit = 12000, cnt = 0;
void countInRange(ll aNum, ll aDenom, ll bNum, ll bDenom)
{
	ll mediantNum = aNum+bNum, mediantDenom = aDenom + bDenom;
	if(mediantDenom > limit)
	{
		return;
	}
	else
	{
		cnt++;
		countInRange(mediantNum, mediantDenom, bNum, bDenom);
		countInRange(aNum, aDenom, mediantNum, mediantDenom);
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll aNum = 1, aDenom = 3, bNum = 1, bDenom = 2;
	countInRange(aNum, aDenom, bNum, bDenom);
	cout << cnt;
	return 0;
}
