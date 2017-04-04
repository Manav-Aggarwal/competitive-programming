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
		int n; 
		cin >> n;
		string s;
		cin >> s;
		char large = 'A', small = 'Z';
		for(int i = 0; i < n; i++)
		{
			if(s[i] > large)
			{
				large = s[i];
			}
			else if(s[i] <= small)
			{
				small = s[i];
			}
		}
		
		
	}
	return 0;
}
