#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int DigitSum(long long int n)
{
	int l = log10(n) + 1;
	int sum = 0;
	while(l--)
	{
		sum += n%10;
		n= n/10;
	}
	if(sum >= 10)
	{
		return DigitSum(sum);
	}
	else{
		return sum;
	}
}

int main()
{	
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cout << DigitSum(n);
	return 0;
}
