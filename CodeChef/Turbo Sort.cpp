#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	vector<long long int> vec;
	for(long long int i = 0; i < t; i++)
	{
		long long int e;
		cin >> e;
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < t; i++)
	{
		cout << vec[i] << endl;
	}
	return 0;
}
