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
		int n, sum = 0, zerosebadekitne = 0;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int k; cin >> k; sum += k;
			k > 0 ? zerosebadekitne++ : zerosebadekitne;
		}
		if(sum >= 100 && sum-zerosebadekitne < 100)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
