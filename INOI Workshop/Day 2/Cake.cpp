/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 1000011
#define mp make_pair
#define pii pair<ll, ll> 

struct cakePiece 
{
	ll weight;
	ll cuts;
	cakePiece (ll wt) 
	{
		weight = wt;
		cuts = 1;
	}
	cakePiece () 
	{
		cuts = 1;
	}
}cakes[MAX];
bool operator<(const cakePiece & x, const cakePiece & y) 
{
	return ((x.weight * y.cuts) < (y.weight * x.cuts));
}
cakePiece operator-(const cakePiece & x, cakePiece & y) 
{
	cakePiece diff = cakePiece((x.weight * y.cuts) - (y.weight * x.cuts));
	diff.cuts = x.cuts * y.cuts;
	return diff;
}
ll cuts[MAX], weights[MAX];
priority_queue< cakePiece > getMax;
int main()
{	
	ios_base::sync_with_stdio(false);
	ll n, maxCuts, i, k;
	cin >> n >> maxCuts;
	for(i = 0; i < n; i++)
	{
		cin >> k; 
		cakes[i].weight = k;
		cakes[i].cuts = 1;
		getMax.push(cakes[i]);
	}
	sort(cakes, cakes+n);
	cakePiece minDiff = cakes[n-1] - cakes[0];
	for(i = 0; i < maxCuts; i++)
	{
		cakePiece curr = getMax.top(); 
		getMax.pop();
		curr.cuts++;
		if(curr < cakes[0])
		{
			cakes[0] = curr;
		}
		getMax.push(curr);
		curr = getMax.top() - cakes[0];
		if(curr < minDiff)
		{
			minDiff = curr;
		}
	}
	long double num = minDiff.weight;
	long double denom = minDiff.cuts;
	cout << fixed << setprecision(7) << num/denom << '\n';
	return 0;
}
