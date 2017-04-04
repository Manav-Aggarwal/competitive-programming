/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 5555555
ll calcA(ll x, ll y)
{
	return (x % 100 + 1) * (y % 100 + 1);
}
ll calcS(ll x)
{
	return (78901 + 31*x) % 699037;
}
ll calcT(ll y)
{
	return (23456 + 64*y) % 2097151;
}
ll s[MAX], t[MAX], a[MAX], sumA[MAX];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll test;
	cin >> test;
	while(test--)
	{
		 ll x, y, N, M, i, j, maxK = 1;
		 cin >> x >> y >> N >> M;
		 s[0] = x; t[0] = y;
		 a[0] = calcA(s[0], t[0]);
		 for(i = 1; i < N; i++)
		 {
		 	s[i] = calcS(s[i-1]);
		 	t[i] = calcT(t[i-1]);
		 	a[i] = calcA(s[i], t[i]);
		 	if(a[i] > M)
		 	{
		 		maxK = 0;
			}
		 }
		 sumA[0] = 0;
		 for(i = 1; i <= N; i++)
		 {
		 	sumA[i] = sumA[i-1] + a[i-1];
		 }
		 if(maxK == 0)
		 {
		 	cout << maxK << endl;
		 	continue;
		 }
		 bool flag = true;
		 /*for(i = 2; i <= N && flag; i++)
		 {
		 	for(j = i; j <= N; j++)
		 	{
		 		if(sumA[j] - sumA[j - i] > M)
		 		{
		 			maxK = i-1;
		 			flag = false;
		 			break;
				}
			}
		 }*/
		 ll start = 1, end = N, mid;
		 while(start >= 1 && end <= N)
		 {
		 	flag = true;
		 	mid = (start + end)/2;
		 	if(end - start <= 1) 
		 	{
		 		if(start == end - 1)
		 		{
		 			for(j = end; j <= N; j++)
				 	{
				 		if(sumA[j] - sumA[j - end] > M)
				 		{
				 			flag = false;
				 			break;
						}
					}
					if(!flag)
					{
						end = start;
					}
				}
		 		break;
			}
		 	for(j = mid; j <= N; j++)
		 	{
		 		if(sumA[j] - sumA[j - mid] > M)
		 		{
		 			end = mid - 1;
		 			flag = false;
		 			break;
				}
			}
			if(flag)
			{
				start = mid;
			}
		 }
		 cout << end << endl;
	}
	return 0;
}
