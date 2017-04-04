/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000
ll stations[M+1];
ll Sums[M+1];
ll BestSumK[M+1];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k, i, sum = 0, bestSoFar;
	cin >> n >> k;
	for(i = 1; i <= n; i++)
	{
		cin >> stations[i];
	}
	for(i = 1; i <= k; i++)
	{
		sum += stations[i];
	}
	Sums[k] = sum;
	BestSumK[k] = sum;
	bestSoFar = sum;
	for(i = k+1; i <= n; i++)
	{
		Sums[i] = Sums[i-1] + stations[i] - stations[i-k];
		BestSumK[i] = max(BestSumK[i-1] + stations[i], Sums[i]);
		bestSoFar = max(bestSoFar, BestSumK[i]);
	}
	cout << bestSoFar;
	return 0;
}
