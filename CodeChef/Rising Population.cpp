#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int alphaM[26], alphaW[26];
		bool flag = true;
		for(int i = 0; i < 26; i++)
		{
			alphaM[i] = 0;
		}
		for(int i = 0; i < 26; i++)
		{
			alphaW[i] = 0;
		}
		string M , W;
		char temp;
		cin >> M >> W;
		if(M.length() != W.length())
		{
			flag = false;
		}
		else
		{
			for(int i = 0; i < M.length(); i++)
			{
				temp = M[i] - 'a';
				alphaM[temp]++;
			}
			for(int i = 0; i < W.length(); i++)
			{
				temp = W[i] - 'a';
				alphaW[temp]++;
			}
			for(int i = 0; i < 26; i++)
			{
				if(alphaW[i] != alphaM[i])
				{
					flag = false;
					break;
				}
			}
		}
		string out = (flag == true) ? "YES" : "NO";
		cout << out << endl;
	}
	return 0;
}
