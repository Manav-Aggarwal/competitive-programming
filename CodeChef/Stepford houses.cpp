#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool waytoSort(pair<long long int, int> a, pair<long long int, long long int> b)
{
	return (a.first < b.first);
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, count = 0;
	cin >> n;
	pair<long long int, long long int>  houses[n];
	for(int i = 0; i < n; i++)
	{
		cin >> houses[i].first;
		houses[i].second = i;
	}
	sort(houses, houses + n, waytoSort);
	for(int i = 0; i < n; i++)
	{
		if(i < houses[i].second)
		{
			count += houses[i].second - i;
		}
	}
	cout << count << endl;
	return 0;
}
