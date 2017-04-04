#include <iostream>
using namespace std;
bool isFibo(unsigned long long int a);
void Caller(unsigned long long int test);
int main()
{
	unsigned int noOfTestCases;
	cin >> noOfTestCases;
	while (noOfTestCases--)
    {
        unsigned long long int num = 0;
        cin >> num;
        Caller(num);
    }
	return 0;
}
bool isFibo(unsigned long long int a)
{
	unsigned long long int first = 0, second = 1, next;
	for (int i = 0;;i++)
	{
		next = first + second;
		first = second;
		second = next;
		if (next == a)
		{
			return true;
		}
		else if(next>a)
		{
			return false;
		}
	}
}
void Caller(unsigned long long int test)
{
     if (isFibo(test))
	{
		cout << "IsFibo" << endl;
	}
	else
	{
		cout << "IsNotFibo" << endl;
	}
}
