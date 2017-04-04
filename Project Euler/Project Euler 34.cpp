/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll log_10(ll num)
{
	ll ans = 0;
	num/=10;
	while(num)
	{
		num/=10;
		ans++;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll factorials[10];
	ll a, b, c, d, e, f, i, num, sum, lg;
	vector<ll> nums;
	factorials[0] = factorials[1] = 1;
	for(i = 2; i < 10; i++)
	{
		factorials[i] = factorials[i-1]*i;
	}
	for(a = 0; a < 10; a++)
	{
		for(b = 0; b < 10; b++)
		{
			for(c = 0; c < 10; c++)
			{
				for(d = 0; d < 10; d++)
				{
					for(e = 0; e < 10; e++)
					{
						for(f = 0; f < 10; f++)
						{
							num = a*100000 + b*10000 + c*1000 + d*100 + e*10 + f;
							if(num > 9)
							{
								lg = log_10(num);
								if(lg == 1)
									sum = factorials[e] + factorials[f];
								else if(lg == 2)
									sum = factorials[d] + factorials[e] + factorials[f]; 
								else if(lg == 3)
									sum = factorials[c] + factorials[d] + factorials[e] + factorials[f]; 
								else if(lg == 4)
									sum = factorials[b] + factorials[c] + factorials[d] + factorials[e] + factorials[f];
								else if(lg == 5)
									sum = factorials[a] + factorials[b] + factorials[c] + factorials[d] + factorials[e] + factorials[f];
							}
							if(sum == num)
							{
								nums.push_back(num);
							}
						}
					}
				}
			}
		}
	}
	for(i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	return 0;
}
