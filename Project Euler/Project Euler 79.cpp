/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("output.out", "w", stdout);
	ifstream file("keylog.txt");
	stringstream buffer;
	buffer << file.rdbuf();
	string test = buffer.str(), tmp = "";
	vector<string> keylogs;
	ll i, countFirst[10], countSecond[10], countThird[10];
	for(i = 0; i < 10; i++)
	{
		countFirst[i] = 0;
		countSecond[i] = 0;
		countThird[i] = 0;
	}
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] == '\n')
		{
			keylogs.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp += test[i];
		}
	}
	keylogs.push_back(tmp);
	for(i = 0; i < keylogs.size(); i++)
	{
		countFirst[keylogs[i][0] - '0']++;
		countSecond[keylogs[i][1] - '0']++;
		countThird[keylogs[i][2] - '0']++;
	}
	for(i = 0; i < 10; i++)
	{
		cout << "For " << i << endl << "There are " << countFirst[i] << " occurences at first pos" << endl;
		cout << "There are " << countSecond[i] << " occurences at second pos" << endl;
		cout << "There are " << countThird[i] << " occurences at third pos" << endl;
	}
	//From the output, I logically deduced the key was 73162890.
	return 0;
}
