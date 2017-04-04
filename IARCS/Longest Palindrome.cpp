/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool table[5555][5555];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, k, maxL = 1, startI = 0;
	string word;
	cin >> n >> word;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
			{
				table[i][j] = true;
			}
			else
			{
				table[i][j] = false;
			}
		}
	}
	for(i = 0; i < n-1; i++)
	{
		if(word[i] == word[i+1])
		{
			table[i][i+1] = true; 
			startI = i;
			maxL = 2;
		}
	}
	for(i = 3; i <= n; i++) // length
	{
		for(j = 0; j < n-i + 1; j++)
		{
			k = j + i - 1;
			if(table[j+1][k-1] == true && word[j] == word[k])
			{
				table[j][k] = true;
				if(i > maxL)
				{
					maxL = i;
					startI = j;
				}
			}
		}
	}
	cout << maxL << endl;
	cout << word.substr(startI, maxL);
	return 0;
}
