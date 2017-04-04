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
		long long int N, i, k, uj;
		cin >> N;
		long long int playlist[N];
		for(i = 0; i < N; i++)
		{
			cin >> playlist[i];
		}
		cin >> k;
		k--;
		uj = playlist[k];
		sort(playlist, playlist + N);
		i = 0;
		while(playlist[i] != uj)
		{
			i++;
		}
		cout <<  i+1 << endl;
	}
	return 0;
}
