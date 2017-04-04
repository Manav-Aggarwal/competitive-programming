#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int fc[64];
void pre()
{
	fc[1] = 2;
	fc[2] = 3;
	for(int i = 3; i <= 64; i++)
	{
		fc[i] = fc[i-1] + fc[i-2];
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	pre();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << fc[n] << endl;
	}
	return 0;
}
