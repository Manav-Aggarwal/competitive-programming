#include <iostream>
using namespace std;
bool isPalindrome(int a);
unsigned long long int nextPal(unsigned long long int x);
int main()
{
	int noOfTestCases;
	cin >> noOfTestCases;
	while(noOfTestCases--)
	{
		unsigned long long int num;
		cin >> num;
		cout << nextPal(num) << endl;
	}
	return 0;
}
bool isPalindrome( unsigned long long int a)
{
	 unsigned long long int num = a;
	 unsigned long long int palA = 0;
	while(a!=0)
	{
		int r  = a%10;
		a/=10;
		palA = palA*10 + r;
	}
	return (num == palA) ? true : false;
}
unsigned long long int nextPal( unsigned long long int x)
{
	do
	{
		x++;
	} while(!(isPalindrome(x)));
	return x;
}
