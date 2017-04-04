/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool wayToSort(ll a, ll b) {return a > b;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, book1, book2, sum = 0, minN;
	vector<ll> books;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> book1 >> book2;
		books.push_back(abs(book1-book2));
	}
	/*Balanced Partitioning*/
	for(i = 0; i < n; i++)
	{
		sum += books[i];
	}
	bool subset[sum+1][n+1];
	for(i = 0; i <= n; i++)
	{
		subset[0][i] = true;
	}
	for(i = 1; i <= sum; i++)
	{
		subset[i][0] = false;
	}
	for(i = 1; i <= sum; i++)
	{
		for(j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j-1];
			if(i >= books[j-1])
			{
				subset[i][j] = subset[i][j] || subset[i-books[j-1]][j-1];
			}
		}
	}
	minN = INT_MAX;
	for(i = 1; i <= sum; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(subset[i][j] == true)
			{
				minN = min(minN, abs(sum - 2*i));
			}
		}
	}
	cout << minN;
	return 0;
}
