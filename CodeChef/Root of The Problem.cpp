/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, id, sum, root;
		cin >> n;
		root = 0;
		while(n--)
		{
			cin >> id >> sum;
			root += id - sum;
		}
		cout << root << endl;
	}
	return 0;
}
