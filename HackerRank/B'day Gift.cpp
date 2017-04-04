#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	double sum = 0;
	setprecision(1);
	while(N--)
	{
		double add;
		cin >> add;
		sum +=add;
	}
	cout << sum/2;
	return 0;
}
