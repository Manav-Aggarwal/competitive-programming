#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	while(T--)
	{
		int p, count = 0, power; 
		cin >> p;
		power = log2(p)+1;
		if(power > 11)
		{
			power = 11;
		}
		while(p!=0)
		{
			if(p >= arr[power])
			{
				p-= arr[power];
				count++;
			}
			else
			{
				power--;
			}
		}
		cout << count << endl;
	}
	return 0;
}
