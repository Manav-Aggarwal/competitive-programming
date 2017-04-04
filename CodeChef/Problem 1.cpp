#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int power10(int k)
{
	int p = 1;
	while(k--)
	{
		p*= 10;
	}
	return p;
}
int reversednum(int n)
{
	int num = 0;
	int len = log10(n)+1;
	int dup = len - 1;
	while(len--)
	{
		int e = n % 10;
		int k = power10(dup);
		num = e*k + num;
		n/=10; dup--;
	}
	return num;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, n1, sum = 0;
		cin >> n >> n1;
		n = reversednum(n);
		n1 = reversednum(n1);
		sum = n + n1;
		cout << reversednum(sum) << endl;
	}
	return 0;
}
