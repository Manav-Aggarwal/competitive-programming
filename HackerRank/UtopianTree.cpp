#include <iostream>
using namespace std;
int  utopianTree(int num);
int main()
{
	int noOfTestCases, num;
	cin >> noOfTestCases;
	while(noOfTestCases--)
	{
		cin >> num;
		utopianTree(num);
	}
	return 0;
}
int utopianTree(int num)
{
	int height = 1;
	for (int i=1; i<=num;i++)
	{
		if(i%2 != 0)
		{
			height *=2;
		}
		else if(i%2 == 0)
		{
			height +=1;
		}
	}
	cout << height << endl;
	return 0;
}
