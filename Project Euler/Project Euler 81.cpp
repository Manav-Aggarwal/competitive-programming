/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll stringToNum(string str)
{
	ll i, num = 0;
	for(i = 0; i < str.length(); i++)
	{
		num += (ll)str[i] - '0';
		num*= 10;
	}
	return num/10;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream file("matrix.txt");
	stringstream buffer;
	buffer << file.rdbuf();
	string test = buffer.str(), tmp = "";
	ll i, j;
	vector<vector<ll> > grid;
	vector<ll> line;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == ',')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
		}	
		else if(test[i] == '\n')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
			grid.push_back(line);
			line.clear();
		}
		else
		{
			tmp += test[i];
		}
	}
	j = grid.size()-1;
	for(i = grid.size()-2; i >= 0; i--)
	{
		grid[i][j] += grid[i+1][j];
		grid[j][i] += grid[j][i+1];
	}
	for(i = grid.size()-2; i >= 0; i--)
	{
		for(j = grid[i].size()-2; j >= 0; j--)
		{
			grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
		}
	}
	cout << grid[0][0];
	return 0;
}
