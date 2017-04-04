/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 300010
ll MOD = 1e9 + 7;
struct node
{
	mutable bool left, right;
	ll key;
	mutable ll position, index;
	bool operator < (node other) const
	{
		return key < other.key;
	}
};

set<node> vals;
ll arr[MAX];
void insrt(node k)
{
	ll num;
	if(k.index == 0)
	{
		k.position = 1;
		num = 1;
		vals.insert(k);
	}
	else
	{
		vals.insert(k);
		auto it = vals.find(k);
		auto it1 = it; it1++;
		if(it == vals.begin())
		{
			it++;
			if(!(it -> left))
			{
				it -> left = true;
				num = ((it -> position)*2);
				num %= MOD;
				--it;
				it -> position = num;
			}
		}
		else if(it1 == vals.end())
		{
			it1--; it1--;
			if(!(it1->right))
			{
				it1 -> right = true;
				num = (it1 -> position)*2 + 1;
				num %= MOD;
				++it1;
				it1 -> position = num;
			}
		}
		else
		{
			it--;
			if(!(it -> right))
			{
				it -> right = true;
				num = (it -> position)*2 + 1;
				num %= MOD;
				++it;
				it -> position = num;
			}
			else if(!(it1 -> left))
			{
				it1 -> left = true;
				num = (it1 -> position)*2;
				num %= MOD;
				--it1;
				it1 -> position = num;
			}
		}
	}
	arr[k.index] = num % MOD;
}
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, i, num;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		node k;
		cin >> k.key;
		k.left = k.right = false;
		k.index = i;
		insrt(k);
		num = arr[i] % MOD;
		cout << num << " ";
	}
    return 0;
}
