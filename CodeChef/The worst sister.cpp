#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int fact[14];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i < 14; i++)
	{
		fact[i] = i * fact[i-1];
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n >= 8 && n <= 13)
		{
			cout << fact[n] << endl;
		}
		else if(n < 8)
		{
			cout << "Underflow!" << endl;
		}
		else if(n > 13)
		{
			cout << "Overflow!" << endl;
		}
	}
	return 0;
}
