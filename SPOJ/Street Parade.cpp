/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		ll n, i, num, tp;
		cin >> n;
		if(n == 0)
		{
			break;
		}
		queue<ll> parade;
		stack<ll> side;
		for(i = 1; i <= n; i++)
		{
			cin >> num;
			parade.push(num);
		}
		num = 1;
		while(!parade.empty())
		{
			tp = parade.front();
			parade.pop();
			if(tp != num)
			{
				side.push(tp);
			}
			else
				num++;
			if(!side.empty())
			{
				tp = side.top();
				while(tp == num)
				{
					side.pop();
					num++;
					if(!side.empty())
						tp = side.top();
				}
			}
			
		}
		if(side.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
