#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s;
long long int getcnt(char c1, char c2, char c3)
{
	long long int cnt2 = 0, cnt3 = 0, i, ans = 0;
	for(i = 0; i < s.length(); i++)
	{
		if(s[i] == c1)
		{
			ans += cnt2 + cnt3;
		}
		else if(s[i] == c2)
		{
			cnt2++;
			ans += cnt3;
		}
		else if(s[i] == c3)
		{
			cnt3++;
		}
	}
	return ans;
}
long long int mintime()
{
	return min(min(min(min(min(getcnt('g', 'r', 'b'), getcnt('g', 'b', 'r')), getcnt('b', 'g', 'r')), getcnt('b', 'r', 'g')), getcnt('r', 'b' ,'g')), getcnt('r', 'g', 'b'));
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		cout << mintime() << endl;
	}
	return 0;
}
