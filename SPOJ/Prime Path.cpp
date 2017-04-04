/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mp make_pair
string numToString(ll num)
{
	ll i;
	string str = "";
	while(num != 0)
	{
		str += (char)( (num%10) + '0');
		num/=10;
	}
	str = string(str.rbegin(), str.rend());
	return str;
}
map<string, bool> isPrime;
map<ll, bool> primeCheck;
void sieve()
{
	ll i, j;
	for(i = 2; i <= 9999; i++)
	{
		primeCheck[i] = true;
	}
	for(i = 2; i <= sqrt(9999); i++)
	{
		if(primeCheck[i])
		{
			for(j = 2*i; j <= 9999; j += i)
			{
				primeCheck[j] = false;
			}
		}
	}
	for(i = 1001; i <= 9999; i++)
	{
		if(primeCheck[i])
		{
			isPrime[numToString(i)] = true;
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll t;
	cin >> t;
	while(t--)
	{
		string num1, num2, currNum, nextNum;
		cin >> num1 >> num2;
		queue<string> frontier;
		ll i, iter;
		frontier.push(num1);
		map<string, string> came_from;
		map<string, bool> visited;
		came_from[num1] = "-1";
		visited[num1] = true;
		while(!frontier.empty())
		{
			currNum = frontier.front();
			frontier.pop();
			if(currNum == num2)
			{
				break;
			}
			for(i = 0; i < 4; i++)
			{
				if(currNum[i] == num2[i])
					continue;
				char j;
				for(j = '0'; j <= '9'; j++)
				{
					if(j == currNum[i] || (i == 0 && j == '0'))
						continue;
					nextNum = currNum;
					nextNum[i] = j;
					if(isPrime[nextNum] && !visited[nextNum])
					{
						frontier.push(nextNum);
						came_from[nextNum] = currNum;
						visited[nextNum] = true;
					}
				}
			}
		}
		stack<string> k;
		while(came_from[currNum] != "-1")
		{
			k.push(currNum);
			currNum = came_from[currNum];
		}
		cout << k.size() << endl;
	}
	return 0;
}
