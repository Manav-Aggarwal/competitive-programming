#include <iostream>
using namespace std;
int altChar(string str);
int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		string test;
		cin >> test;
		cout << altChar(test) <<endl;
	} 
	return 0;
}
int altChar(string str)
{
	int numDel = 0;
	for (int i = 0; i < str.length()-1; i++)
	{
		if (str[i] == str[i+1])
		{
			numDel++;
		}
	}
	return numDel;
}
