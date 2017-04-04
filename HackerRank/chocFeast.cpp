#include <iostream>
using namespace std;
int TotalChocs(int n, int c, int m);
int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		int n, c, m;
		cin >> n >> c >> m;
		cout << TotalChocs(n,c,m) << endl;
	}
	return 0;
}
int TotalChocs(int n, int c, int m)
{
	int tot  = 0;
	int left;
	tot += n/c;
	if (tot >= m)
	{
		left = tot;
		do
		{
			left -= m;
			tot++; left++;
		} while(left >=m);
	}
	return tot;
	
}
