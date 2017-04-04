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
		ll n;
		cin >> n;
		if(n == 0)
			break;
		ll arr[n], i, j, maxArea = 0, tp;
		stack<ll> frontier;
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for(i = 0; i < n;)
		{
			if(frontier.empty() || arr[frontier.top()] <= arr[i])
			{
				frontier.push(i++);
			}
			else
			{
				tp = frontier.top();
				frontier.pop();
				if(frontier.empty())
					maxArea = max(maxArea, arr[tp] * i);
				else
				{
					maxArea = max(maxArea, arr[tp] * (i - frontier.top() - 1));
				}
			}
		}
		while(!frontier.empty())
		{
			tp = frontier.top();
			frontier.pop();
			if(frontier.empty())
				maxArea = max(maxArea, arr[tp] * i);
			else
				maxArea = max(maxArea, arr[tp] * (i - frontier.top() - 1));
		}
		cout << maxArea << endl;
	}
	return 0;
}
