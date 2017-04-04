/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool isPrime(ll n) 
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n < 9) return true;
    if (n % 3 == 0) return false;
    ll counter = 5;   
    while ((counter * counter) <= n) {
    if (n % counter == 0) return false;
	if (n % (counter + 2) == 0) return false;
        counter += 6;
	}
    return true;
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll s = 7, toAdd = 30, bl = 43, tl = 37, tr = 31, nums = 13, numPrime = 8; // bl = bottom-left, tr = top-right
	double ratio = 62.0;
	while(ratio >= 10.0)
	{
		bl += toAdd;
		if(isPrime(bl))
		{
			numPrime++;
		}
		tl += toAdd - 2;
		if(isPrime(tl))
		{
			numPrime++;
		}
		tr += toAdd - 4;
		if(isPrime(tr))
		{
			numPrime++;
		}
		toAdd += 8;
		s += 2;
		nums += 4;
		ratio = ((numPrime*100)/nums);
	}
	cout << s;
	return 0;
}
