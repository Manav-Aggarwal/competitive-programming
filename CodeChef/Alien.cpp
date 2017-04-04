#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int smallestfact(int n)
{
	int root = sqrt(n), i;
	for(i = 2; i <= n; i++)
	{
		if(n % i == 0)
		{
			break;
		}
	}
	return i;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, sum = 0, k, d, sf;
	cin >> n;
	sum += n;
	k = n;
	while (k != 1)
	{
		sf = smallestfact(k);
		d = k/sf;
		sum += d;
		k = d;
	}
	cout << sum << endl;
	return 0;
}
