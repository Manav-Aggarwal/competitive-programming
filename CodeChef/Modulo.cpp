#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 10;
	set<int> n;
	while(t--)
	{
		n.clear();
		for(int i = 0; i < 10; i++)
		{
			int k;
			cin >> k;
			k = k % 42;
			n.insert(k);
		}
		cout << n.size() << endl;
	}
	return 0;
}
