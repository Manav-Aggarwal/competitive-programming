/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
ll M = 10000;
ll arr[10001];
vector<ll> primes;
void sieveOfEratosthenes()
{
	long long i, j;
	for(i = 2; i <= M; i++)
	{
		arr[i] = 1;
	}
	arr[0] = arr[1] = 0;
	for(i = 2; i <= sqrt(M); i++)
	{
		if(arr[i] == 1)
		{
			for(j = 2*i; j <= M; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
	primes.push_back(2);
	for(i = 3; i <= M; i += 2)
	{
		if(arr[i])
		{
			primes.push_back(i);
		}
	}
}
ll power10(ll num)
{
	ll ans = 1;
	while(num--)
	{
		ans*=10;
	}
	return ans;
}
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

ll check(ll num1, ll num2)
{
	return (!(isPrime((ll)(num1 * power10((log(num2)/log(10)) + 1) + num2))) || !(isPrime((ll)(num2 * power10((log(num1)/log(10)) + 1) + num1))));
}

ll canBeConcatenated(ll num1, ll num2)
{
	return ((isPrime((ll)(num1 * power10((log(num2)/log(10)) + 1) + num2))) && (isPrime((ll)(num2 * power10((log(num1)/log(10)) + 1) + num1))));
}
vector<ll> setArr[1234];
vector<ll> intersections[1234][1234];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieveOfEratosthenes();
	ll i, j, k, primeToAdd = 0, size = primes.size();
	bool isPossible;
	for(i = 1; i < size-1; i++)
	{
		for(j = 1; j < size; j++)
		{
			isPossible = true;
			if(check(primes[i], primes[j]))
			{
				isPossible = false;
			} 
			if(isPossible)
			{
				setArr[i].push_back(primes[j]);
			}
		}
	}
	for(i = 1; i < size - 1; i++)
	{
		for(k = 0; k < setArr[i].size(); k++)
		{
			for(j = i + 1; j < size; j++)
			{
				if(binary_search(setArr[j].begin(), setArr[j].end(), setArr[i][k]) && binary_search(setArr[i].begin(), setArr[i].end(), primes[j]))
				{
					intersections[i][j].push_back(setArr[i][k]);
				}
			}
		}
	}
	vector<pair<ll, ll> > ijs;
	ll cnt = 0, x, y, z, z1, z2, num1, num2, num3, sum = 0;
	set<ll> list;
	set<set<ll> > lists;
	for(i = 0; i < size - 1; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(intersections[i][j].size() > 2)
			{
				ijs.push_back(make_pair(i, j));
			}
		}
	}
	for(i = 0; i < ijs.size(); i++)
	{
		x = ijs[i].first;
		y = ijs[i].second;
		for(z = 0; z < intersections[x][y].size() - 2; z++)
		{
			for(z1 = z + 1; z1 < intersections[x][y].size() - 1; z1++)
			{
				for(z2 = z1 + 1; z2 < intersections[x][y].size(); z2++)
				{
					num1 = intersections[x][y][z];
					num2 = intersections[x][y][z1];
					num3 = intersections[x][y][z2];
					if(canBeConcatenated(num1, num2) && canBeConcatenated(num2, num3) && canBeConcatenated(num1, num3))
					{
						list.clear();
						list.insert(primes[x]);
						list.insert(primes[y]);
						list.insert(num1);
						list.insert(num2);
						list.insert(num3);
						lists.insert(list);
					}
				}
				
			}
		}
	}
	set<ll>::iterator it2;
	set<set<ll> >::iterator it1;
	for(it1 = lists.begin(); it1 != lists.end(); it1++)
	{
		for(it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			cout << *it2 << " ";
			sum += *it2;
		}
		cout << endl;
	}
	cout << sum;
	return 0;
}
