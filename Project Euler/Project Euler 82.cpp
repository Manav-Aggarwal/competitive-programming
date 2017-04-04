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
	vector<vector<ll> > grid; 
	vector<ll> line;
	ll i, j, minSum = INT_MAX;
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
	ll soln[grid.size()];
	for(i = 0; i < grid.size(); i++)
	{
		soln[i] = grid[i][grid.size()-1];
	}
	for(i = grid.size()-2; i >= 0; i--)
	{
		soln[0] += grid[0][i];
		//Go Down
		for(j = 1; j < grid.size(); j++)
		{
			soln[j] = min(soln[j-1] + grid[j][i], soln[j] + grid[j][i]);
		}
		
		// Go Up
		for(j = grid.size()-2; j >= 0; j--)
		{
			soln[j] = min(soln[j], soln[j+1] + grid[j][i]);
		}
 	}
	for(i = 0; i < grid.size(); i++)
	{
		minSum = min(minSum, soln[i]);
	}
	cout << minSum;
	return 0;
}
