#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
int main()
{	
	int T;
	cin >> T;
	while(T--)
	{
		ull N, sum = 0;
		cin >> N;
		ull first = 1, second = 1, next=0;
		while(next < N)
		{
			if(!(next&1))
			{
				sum += next;
			}
			next = first + second;
			first = second;
			second = next;
			
		}
		cout << sum << endl;
	}
	return 0;
}
