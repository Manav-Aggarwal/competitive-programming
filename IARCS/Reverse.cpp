/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j;
	cin >> n;
	cin.ignore();
	string arr[n], temp;
	for(i = n-1; i >= 0; i--)
	{
		getline(cin, arr[i]);
		arr[i].erase(remove(arr[i].begin(), arr[i].end(), ','), arr[i].end());
		arr[i].erase(remove(arr[i].begin(), arr[i].end(), '\''), arr[i].end());
		arr[i].erase(remove(arr[i].begin(), arr[i].end(), ':'), arr[i].end());
		arr[i].erase(remove(arr[i].begin(), arr[i].end(), ';'), arr[i].end());
		arr[i].erase(remove(arr[i].begin(), arr[i].end(), '.'), arr[i].end());
	}
	for(i = 0; i < n; i++)
	{
		temp = "";
		for(j = arr[i].length()-1; j >= 0; j--)
		{
			if(arr[i][j] == ' ')
			{
				cout << string(temp.rbegin(), temp.rend()) << " ";
				temp = "";
			}
			else
			{
				temp += arr[i][j];
			}
		}
		cout << string(temp.rbegin(), temp.rend());
		temp = "";
		cout << endl;
	}
	return 0;
}
