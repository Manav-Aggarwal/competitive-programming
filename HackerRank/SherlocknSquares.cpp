#include <iostream>
#include <math.h>
using namespace std;
int Sqbtwint(int a, int b);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << Sqbtwint(a, b) << endl;
	}
	return 0;

}
int Sqbtwint(int a, int b)
{
	int cnt = 0;
	int i = 1;
	int square = pow(i,2);
	while(square <= b)
	{
		if(square < a)
		{
			
		}
		else
		{
			cnt++;
		}
		i++;
		square = pow(i, 2);
	}
	return cnt;
}
