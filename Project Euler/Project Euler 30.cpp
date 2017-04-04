/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ll fifthPowers[10];
	ll i, a, b, c, d, e, f, num, sum = -1;
	for(i = 0; i < 10; i++)
	{
		fifthPowers[i] = (ll)pow(digits[i], 5);
	}
	vector<ll> nums;
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
							if(fifthPowers[a] + fifthPowers[b] + fifthPowers[c] + fifthPowers[d] + fifthPowers[e] + fifthPowers[f]== num)
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
		sum += nums[i];
	}
	cout << "Sum : " << sum;
	return 0;
}
