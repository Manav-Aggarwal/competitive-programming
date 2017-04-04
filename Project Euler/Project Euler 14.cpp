/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
bool arr[1000000];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll maxSize = 0, i, size, num = 0, largestNum;
	for(i = 999999; i >= 0; i--)
	{
		if(arr[i])
		{
			continue;
		}
		size = 1, num = i;
		while(num > 1)
		{
			if(num < 1000000)
			{
				arr[num] = true;
			}
			if(num&1)
			{
				num = 3*num + 1;
			}	
			else
			{
				num /= 2;
			}
			size++;
		}	 
		if(maxSize < size)
		{
			maxSize = size;
			largestNum = i; 
		}
	}
	cout << largestNum;
	return 0;
}
