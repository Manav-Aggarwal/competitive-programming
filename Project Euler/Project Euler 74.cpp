/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll M = 1000000;
ll factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
ll digitFactorialSum(ll num)
{
	ll sum = 0;
	while(num)
	{
		sum += factorials[num%10];
		num/=10;
	}
	return sum;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, tmp, ch, sz, j;
	vector<vector<ll> > chains;
	vector<ll> nums, loop1, loop2, loop3;
	loop1.push_back(169);
	loop1.push_back(1454);
	loop1.push_back(363601);
	
	loop2.push_back(871);
	loop2.push_back(45361);
	
	loop3.push_back(872);
	loop3.push_back(45362);
	for(i = 70; i < M; i++)
	{
		vector<ll> nums;
		tmp = i;
		while(true)
		{
			if(binary_search(loop1.begin(), loop1.end(), tmp))
			{
				ch = 1;
				break;
			}
			else if(binary_search(loop2.begin(), loop2.end(), tmp))
			{
				ch = 2;
				break;
			}
			else if(binary_search(loop3.begin(), loop3.end(), tmp))
			{
				ch = 3;
				break;
			}
			else if(tmp == 145 || tmp == 2 || tmp == 40585)
			{
				ch = 4;
				break;
			}
			else
			{
				ch = 0;
				nums.push_back(tmp);
				tmp = digitFactorialSum(tmp);
			}
		}
		nums.push_back(tmp);
		if(ch == 1)
		{
			tmp = digitFactorialSum(tmp);
			nums.push_back(tmp);
			tmp = digitFactorialSum(tmp);
			nums.push_back(tmp);
		}
		else if(ch == 4 || ch == 5)
		{
			tmp++; tmp--;
		}
		else
		{
			tmp = digitFactorialSum(tmp);
			nums.push_back(tmp);
		}
		sz = nums.size();
		if(sz == 60)
		{
			chains.push_back(nums);
		}	
	}
	cout << chains.size();
	return 0;
}
