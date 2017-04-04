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
		int N, flagy = 0, flagi = 0;
		cin >> N;
		string s;
		cin >> s;
		for(int i = 0; i < N; i++)
		{
			if(s[i] == 'I')
			{
				flagi = 1;
				break;
			}
			if(s[i] == 'Y')
			{
				flagy = 1;
				break;
			}
		}
		if(flagy)
		{
			cout << "NOT INDIAN" << endl;
		}
		else if(flagi)
		{
			cout << "INDIAN" << endl;
		}
		else
		{
			cout << "NOT SURE" << endl;
		}
	}
	return 0;
}
