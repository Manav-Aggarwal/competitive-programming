#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int flag = 0, i, j = 0, k = 0;
		string A, B;
		cin >> A >> B;
		for(i = k; i < A.length(); i++)
		{
			if(j < 5 && A[i] == B[j])
			{
				j++;
			}
			else
			{
				j = 0;
				i = k;
				k++;
			}
			if(j == 5)
			{
				flag = 1;
				break;
			}
		}
		cout << flag << endl;
	}
	return 0;
}
