#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		int N, K, count = 0;
		cin >> N >> K;
		for(int i = 0; i < N; i++)
		{
			int s;
			cin >> s;
			if(s <= 0)
			{
				count++;
			}
		}
		if(count >= K)
		{
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
	return 0;
}
