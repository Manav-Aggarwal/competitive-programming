/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, j, k = 0;
	ll arr[] = {75,
				95, 64,
				17, 47, 82,
				18, 35, 87, 10,
				20, 04, 82, 47, 65,
				19, 01, 23, 75, 03, 34,
				88, 02, 77, 73, 07, 63, 67,
				99, 65, 04, 28, 06, 16, 70, 92,
				41, 41, 26, 56, 83, 40, 80, 70, 33,
				41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
				53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
				70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
				91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
				63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
				04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23
				};
	vector< vector<ll> > triangle; vector<ll> temp;
	for(i = 0; i < 15; i++)
	{
		temp.clear();
		for(j = 0; j < i+1; j++)
		{
			temp.push_back(arr[k]);
			k++;
		}
		triangle.push_back(temp);
	}
	for(i = 13; i >= 0; i--)
	{
		for(j = 0; j < i+1; j++)
		{
			triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
		}
	}
	cout << triangle[0][0];
	return 0;
}
