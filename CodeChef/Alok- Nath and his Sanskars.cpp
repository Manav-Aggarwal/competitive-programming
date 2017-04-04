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
		long long int N, K, sum = 0;
		cin >> N >> K;
		long long int sanskars[N];
		for(int i = 0; i < N; i++)
		{
			cin >> sanskars[i];
			sum += sanskars[i];
		}
		if(sum == 0 && N != K)
		{
			cout << "no" << endl;
			break;
		}
		if(sum % K == 0)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}
