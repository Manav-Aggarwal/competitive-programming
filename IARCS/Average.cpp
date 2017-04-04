/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
double avg(ll a, ll b)
{

	return (a+b)/2.0;
}
vector<ll> arr;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, i, j, low, high, count = 0;
	double num;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for(i = 0; i < n; i++)
	{
		if(arr[i] == arr[i-1] || arr[i] == arr[i+1])
		{
			count++;
		}
		else
		{
			low = i-1;
			high = i+1;
			while(low >= 0 && high < n)
			{
				num = avg(arr[low], arr[high]);
				if(num == (double)arr[i])
				{
					count++;
					break;
				}
				else if(num < arr[i])
				{
					high++;
				}
				else
				{
					low--;
				}
			}
		}

	}
	cout << count;
	return 0;
}
