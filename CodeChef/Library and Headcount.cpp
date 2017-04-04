#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int n;
string s;
string names[50001];
long long int vals[50001];
long long int srch(string k, long long int n)
{
	for(int i = 0; i < n; i++)
	{
		if(names[i] == k)
		{
			return i;	
		}
	}
	return -1;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		long long int n, val, sum = 0;
		cin >> n;
		for(long long int i = 0; i < n; i++)
		{
			cin >> s;
			val = srch(s, n);
			if (val != -1)
			{
				vals[i] = !(vals[i]);
			}
			else
			{
				vals[i] = 1;	
			}
		}
		for(long long int i = 0; i < n; i++)
		{
			sum += vals[i];
		}
		cout << sum << endl;
	}
	return 0;
}
