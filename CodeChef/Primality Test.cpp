/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll M = 111111;
bool arr[M];
void sieveOfEratosthenes()
{
	ll i, j;
	for(i = 2; i < M; i++)
	{
		arr[i] = true;
	}
	for(i = 2; i < sqrt(M); i++)
	{
		if(arr[i] == true)
		{
			for(j = 2*i; j < M; j += i)
			{
				arr[j] = false;
			}
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(arr[n])
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
		cout << endl;
	}
	return 0;
}
