#include <iostream>
using namespace std;
int main()
{
	int noOFTestCases;
	cin >> noOFTestCases;
	while (noOFTestCases--)
	{
		unsigned int num;
		cin >> num;
		cout << ~num << endl;
	}
	return 0;
}

