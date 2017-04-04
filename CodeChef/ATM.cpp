#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cash; 
	double bal;
	cin >> cash >> bal;
	if(bal - 0.5 - cash >= 0 && cash % 5 == 0) 
	{
		cout << fixed << setprecision(2) << bal - cash - 0.5 << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << bal << endl;
	}
	return 0;
}
