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
	ifstream file("triangle.txt");
	stringstream buffer;
	buffer << file.rdbuf();
	string test = buffer.str(), tmp = "";
	vector<vector<ll> > triangle;
	vector<ll> line;
	ll i , j;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == '\n')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
			triangle.push_back(line);
			line.clear();
		}
		else if(test[i] == ' ')
		{
			line.push_back(stringToNum(tmp));
			tmp = "";
		}
		else
		{
			tmp += test[i];
		}
	}
	for(i = triangle.size()-2; i >= 0; i--)
	{	
		for(j = 0; j < i+1; j++)
		{
			triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
		}
	}
	cout << triangle[0][0];
	return 0;
}
