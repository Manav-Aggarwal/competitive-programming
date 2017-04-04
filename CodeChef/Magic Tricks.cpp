#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int matrix[26][1000001];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	string s;
	cin >> s;
	long long int len = s.length(), i , j, val;
	for(i = 0; i < 26; i++)
	{
		for(j = 0; j <= len; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for(i = 1; i <= len; i++)
	{
		val = s[i-1] - 'a';
		for(j = 0; j < 26; j++)
		{
			matrix[j][i] = matrix[j][i-1];
		}
		matrix[val][i]++;
	}
	long long int q;
	cin >> q;
	while(q--)
	{
		char c;
		long long int l, r;
		cin >> c >> l >> r;
		cout << matrix[c - 'a'][r] - matrix[c - 'a'][l-1] << endl;;
	}
	return 0;
}
