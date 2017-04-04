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
		long long int N, lelo, nalo, nalo_naya;
		cin >> N;
		long long int judges[N];
		for(long long int i = 0; i < N; i++)
		{
			cin >> judges[i];
		}
		lelo = judges[0];
		nalo = 0;
		for (long long int i = 1; i < N; i++)
		{
		  nalo_naya = (lelo > nalo)? lelo: nalo;
		  lelo = nalo + judges[i];
		  nalo = nalo_naya;
		}
		cout << ((lelo > nalo)? lelo : nalo) << endl;;
	}
	return 0;
}
