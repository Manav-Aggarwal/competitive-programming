#include <bits/stdc++.h>
using namespace std;
char change(char t)
{
	if(t == '+')
	{
		return '-';
	}
	else
	{
		return '+';
	}
}
int chain(string S)
{
	int count = 0;
	for(int i = 1; i < S.length(); i++)
	{
		char t = S[i];
		if(S[i] == S[i-1])
		{
			S[i] = change(S[i]);
			count++;
		}
	}
	return count;
}
int main()
{	
	//freopen("test.in", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		string S;
		cin >> S;
		string s = S;
		S[0] = change(S[0]);
		cout << min(chain(S)+1, chain(s)) << endl;
	}
	return 0;
}
