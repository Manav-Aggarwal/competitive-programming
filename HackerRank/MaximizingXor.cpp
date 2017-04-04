#include <iostream>
using namespace std;
int MaxXor(int l, int r);
int main()
{
	int l, r;
	cin >> l >> r;
	MaxXor(l, r);
	return 0;
}
int MaxXor(int l, int r)
{
	int max = 0;
	for(int i=l;i<=r;i++)
	{
		for(int j=l;j<=r;j++)
			if(max < (i^j))
			{
				max = i^j;
			}
	}
	cout << max;
	return 0;
	
}
