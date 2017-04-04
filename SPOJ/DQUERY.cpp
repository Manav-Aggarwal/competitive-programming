/* Written By Manav Aggarwal */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
	int L, R;
	int I;
};
node queries[200002];
int block, ans, currL, currR;
bool wayToSort(node a, node b)
{
	if( a.L / block < b.L / block )
		return true;
	if( a.L / block > b.L / block )
		return false;
	return a.R < b.R ;
}

int cnt[200002], arr[30002], freqs[1000002];

void remove( int i ){
	freqs[ arr[i] ]--;
	if( freqs[ arr[i] ] == 0 )
		ans--;
}

void add( int i  ){
	freqs[ arr[i] ]++;
	if( freqs[ arr[i] ] == 1 )
		ans++;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, i, q;
	cin >> n;
	block = sqrt(n);
	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> q;
	for(i = 1; i <= q; i++)
	{
		cin >> queries[i].L >> queries[i].R;
		queries[i].I = i;
	}
	sort(queries+1, queries+q+1, wayToSort);
	currL = currR = ans = 0;
	for(i = 1; i <= q; i++)
	{
		while(currL < queries[i].L)
		{
			remove(currL);
    		currL++;
		}
		while(currL > queries[i].L)
		{
			currL--;
			add(currL);
		}
		while(currR < queries[i].R)
		{
			currR++;
			add(currR);
		}
		while(currR > queries[i].R)
		{
			remove(currR);
    		currR--;
		}
		cnt[queries[i].I] = ans;
	}
	for(i = 1; i <= q; i++)
	{
		cout << cnt[i] << "\n";
	}
	return 0;
}
