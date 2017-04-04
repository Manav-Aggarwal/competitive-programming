#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int num;
		cin >> num;
		cout << (num<=0 ? 0 : num +1) << endl;
	}
	return 0;
}