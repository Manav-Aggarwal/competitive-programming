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
		long long int n;
		cin >> n;
		if(n&1){
			n--;
		}
		cout << n << endl;
	}
	return 0;
}
