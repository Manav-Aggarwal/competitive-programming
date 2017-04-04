/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii make_pair

ll gcd(ll a, ll b) {return b ? gcd(b, a%b): a;}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i, count = 0, root = 1, num, denom = 1, diff, period, outnum, temp;
	set<pair<ll, ll> > tmp;
	for(i = 2; i < 10000; i++)
	{
		if(sqrt(i) != (ll)(sqrt(i)))
		{
			num = i;
			diff = outnum = root;
			denom = i - (diff*diff);
			period = 0;
			while(tmp.count(pii(diff, denom)) == 0)
			{
				tmp.insert(pii(diff, denom));
				outnum = (root + diff)/denom;
				diff = -(diff - denom*outnum);
				num = denom;
				denom = i - (diff*diff);
				temp = gcd(num, denom);
				if(temp != 1)
				{
					num /= temp;
					denom /= temp;
				}
				period++;
			}
			tmp.clear();
			if(period&1)
			{
				count++;
			}
		}
		else
		{
			root++;
		}
	}
	cout << count;
	return 0;
}
