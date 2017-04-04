#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long calc_time(string s)
{
	long long time = 0, key = 1, i;
	for(i = 0; i < s.length(); i++)
	{
		if(s[i] == '.' || s[i] == 'a' || s[i] == 'd' || s[i] == 'g' || s[i] == 'j' || s[i] == 'm' || s[i] == 'p' || s[i] == 't' || s[i] == 'w' || s[i] == '_')
		{
			time+=1;	
		}
		else if(s[i] == ',' || s[i] == 'b' || s[i] == 'e' || s[i] == 'h' || s[i] == 'k' || s[i] == 'n' || s[i] == 'q' || s[i] == 'u' || s[i] == 'x' || s[i] == '0')
		{
			time+=2;
		}
		else if(s[i] == '?' || s[i] == 'c' || s[i] == 'f' || s[i] == 'i' || s[i] == 'l' || s[i] == 'o' || s[i] == 'r' || s[i] == 'v' || s[i] == 'y')
		{
			time+=3;
		}
		else if(s[i] == '!' || s[i] == 's' || s[i] == 'z' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '8')
		{
			time+=4;
		}
		else if(s[i] == '1' || s[i] == '7' || s[i] == '9')
		{
			time+=5;
		}
		
		if(s[i] == '.' || s[i] == ',' || s[i] == '?' || s[i] == '!' || s[i] == '1')
		{
			if(key != 1)
			{
				time++;
				key = 1;
			}
		}
		else if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == '2')
		{
			if(key != 2)
			{
				time++;
				key = 2;
			}
		}
		else if(s[i] == 'd' || s[i] == 'e' || s[i] == 'f' || s[i] == '3')
		{
			if(key != 3)
			{
				time++;
				key = 3;
			}
		}
		else if(s[i] == 'g' || s[i] == 'h' || s[i] == 'i' || s[i] == '4')
		{
			if(key != 4)
			{
				time++;
				key = 4;
			}
		}
		else if(s[i] == 'j' || s[i] == 'k' || s[i] == 'l' || s[i] == '5')
		{
			if(key != 5)
			{
				time++;
				key = 5;
			}
		}
		else if(s[i] == 'm' || s[i] == 'n' || s[i] == 'o' || s[i] == '6')
		{
			if(key != 6)
			{
				time++;
				key = 6;
			}
		}
		else if(s[i] == 'p' || s[i] == 'q' || s[i] == 'r' || s[i] == 's' || s[i] == '7')
		{
			if(key != 7)
			{
				time++;
				key = 7;
			}
		}
		else if(s[i] == 't' || s[i] == 'u' || s[i] == 'v' || s[i] == '8')
		{
			if(key != 8)
			{
				time++;
				key = 8;
			}
		}
		else if(s[i] == 'w' || s[i] == 'x' || s[i] == 'y' || s[i] == 'z' || s[i] == '9')
		{
			if(key != 9)
			{
				time++;
				key = 9;
			}
		}
		else if(s[i] == '_' || s[i] == '0')
		{
			if(key != 0)
			{
				time++;
				key = 0;
			}
		}
	}
	return time;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << calc_time(s) << endl;
	}
	return 0;
}
