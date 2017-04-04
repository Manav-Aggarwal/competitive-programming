/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll wordVal(string str)
{
	ll sum = 0, i;
	for(i = 0; i < str.length(); i++)
	{
		sum += str[i] - 'A' + 1;
	}
	return sum;
}
bool isTriangleNum(ll num)
{
	double n = (sqrt(1 + 8*num) - 1.0)/2;
	if(n == (ll)(n))
	{
		return true;
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream words("words.txt");
	stringstream buffer;
	buffer << words.rdbuf();
	string test = buffer.str();
	test.erase(remove(test.begin(), test.end(), '"'), test.end());
	ll i, greatestVal = 0, count = 0;
	vector<string> wordsArr;
	string temp = "";
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == ',')
		{
			if(wordVal(temp) > greatestVal)
			{
				greatestVal = wordVal(temp);
			}
			wordsArr.push_back(temp);
			temp = "";
		}
		else
		{
			temp += test[i];
		}
	}
	wordsArr.push_back(temp);
	for(i = 0; i < wordsArr.size(); i++)
	{
		if(isTriangleNum( wordVal(wordsArr[i]) ) )
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
