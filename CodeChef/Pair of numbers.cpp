#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, flag =0;
	cin >> n;
	int array[n];
	for(int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int x, s;
	cin >> x;
	for(int i = 0 ; i < n; i++)
	{
		s = x - array[i];
		for(int j = i+1; j < n; j++)
		{
			if(array[j] == s)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			break;
		}
	}
	if(flag == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
