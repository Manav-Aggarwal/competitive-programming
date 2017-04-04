#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int G, I, Q, i, N;
		cin >> G;
		for(i = 0; i < G; i++)
		{
			cin >> I >> N >> Q;
			if(!(N&1))
			{
				cout << N/2 << endl;
			}
			else
			{
				if(I == Q)
				{
					cout << (N-1)/2 << endl;
				}
				else
				{
					cout << (N+1)/2 << endl;
				}
			}
		}
	}
	return 0;
}
