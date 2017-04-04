#include <iostream>
#include <algorithm>
using namespace std;
bool isPalindrome(string s);
int OpCnt(string str);
int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		string test;
		cin >> test;
		cout << OpCnt(test) << endl;
	}
	return 0;
}
int OpCnt(string str)
{
	int OpCnt = 0;
	int len = str.length();
	if(isPalindrome(str))
	{
		return OpCnt;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			while(str[i] != str[len-1-i] && i != len-1-i)
			{
				int a = str[i];
				int b = str[len-1-i];
				int min, max;
				(a<b) ? min = a : min = b;
				(min==a) ? max = b : max = a;
				while (max!=min)
				{
					max--;
					OpCnt ++;
				}
				str[i] = str[len-1-i] = max;
			}
		}
	}
	return OpCnt;
}
bool isPalindrome(string s)
{
	string t = s;
	reverse(s.begin(), s.end());
	if(s==t)
	{
		return true;
	}
	else
	{
		return false;
	}
}
