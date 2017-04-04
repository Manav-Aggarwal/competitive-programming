/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll naiveFactorial(ll n)
{
	ll fact = 1; n++;
	while(--n)
	{
		fact *= n;
	}
	return fact;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<ll> sortedArr(arr, arr+10);
	ll n, size = 10, factN = size - 1, fact, k, i;
	cin >> n; //nth permutation
	n--;
	string perm = "";
	while(true)
	{
		fact = naiveFactorial(factN);
		i = n/fact;
		n %=fact;
		perm += (char)(sortedArr[i] + '0');
		sortedArr.erase(sortedArr.begin() + i);
		if(n == 0)
		{
			break;
		}
		factN--;
	}
	for(i = 0; i < sortedArr.size(); i++)
	{
		perm += (char)(sortedArr[i] + '0');
	}
	cout << perm;
	return 0;
}
