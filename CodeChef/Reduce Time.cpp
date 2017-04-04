#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int rt[100];
void reduce_time()
{
	rt[0] = 1;
	rt[1] = 2;
	for(int i = 2; i < 100; i++)
	{
		rt[i] = rt[i-1] + rt[i-1];
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	reduce_time();
	int n;
	cin >> n;
	cout << rt[n];
	return 0;
}
