/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll DateToDay(ll day, ll month, ll year) //Valid for Dates above 1 Jan, 1900
{
	ll days = 0;
	ll months[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	days += months[month-1];
	days += day - 1;
	if(days < 59 && year % 4 == 0)
	{
		days--;
		if(year % 100 == 0 && year % 400 != 0)
		{
			days++;
		}
	}
	days += ( ( year - 1900) * 365) + ( (year-1900) / 4) - (year/100 - (1900/100) ) + (year/400 - 1900/400);
	return (days + 1)%7;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll d, m, y, SundayCount = 0;
	for(y = 1901; y <= 2000; y++)
	{
		for(m = 1; m <= 12; m++)
		{
			if(DateToDay(1, m, y) == 0)
			{
				SundayCount++;
			}
		}
	}
	cout << SundayCount;
	return 0;
}
