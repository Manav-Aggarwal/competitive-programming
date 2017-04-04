/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll noOfLetters(ll num)
{
	ll sum = 0;
	map<ll, ll> numToLetters;
	numToLetters[0] = 0;
	numToLetters[1] = numToLetters[2] = numToLetters[6] = numToLetters[10] = 3;
	numToLetters[4] = numToLetters[5] = numToLetters[9] = 4; 
	numToLetters[3] = numToLetters[7] = numToLetters[8] = numToLetters[40] = numToLetters[50] = numToLetters[60]  = 5;   
	numToLetters[20] = numToLetters[30] = numToLetters[80] = numToLetters[90] =numToLetters[11] = numToLetters[12]= 6;
	numToLetters[70] = numToLetters[100] = numToLetters[15] = numToLetters[16] = 7;
	numToLetters[13] = numToLetters[14] = numToLetters[18] = numToLetters[19] = numToLetters[1000] = 8;
	numToLetters[17] = 9;
	
	if(num <= 20 || (num % 10 == 0 && num < 100) || num == 1000 )
	{
		return numToLetters[num];
	}
	else if(num <= 99)
	{
		sum += numToLetters[num % 10];
		num/=10;
		sum+= numToLetters[num*10];
		return sum;
	}
	else if(num >= 100 && num % 100 == 0)
	{
		return numToLetters[100] + numToLetters[num/100];
	}
	else 
	{
		sum += noOfLetters(num % 100);
		num/=100;
		sum+= numToLetters[num] + numToLetters[100] + 3;
		return sum;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, sum = 0, n;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		sum += noOfLetters(i);
	}
	cout << sum;
	return 0;
}
