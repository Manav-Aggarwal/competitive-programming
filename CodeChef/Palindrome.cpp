#include <bits/stdc++.h>
#include <string>
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
bool isPal(int n)
{
	string s;
	ostringstream convert;
	convert << n;
	s = convert.str();
	for(int i = 0; i < s.length()/2; i++)
	{
		if(s[i] != s[s.length()-i-1])
		{
			return false;
		}
	}
	return true;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, sum, count = 0;
		cin >> n;
		sum = n;
		while(true)
		{
			sum = sum + reversednum(sum);
			count++;
			if(isPal(sum))
			{
				break;
			}
		}
		cout << count << " " << sum << endl;
	}
	return 0;
}
