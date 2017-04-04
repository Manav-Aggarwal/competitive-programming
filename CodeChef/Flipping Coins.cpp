#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 444444
bool lazytree[MAX];
int Heads[MAX];
ll getMid(ll s, ll e)
{
	return (s+e)/2;
}
ll getHeads(ll l, ll r, ll start, ll end, ll node)
{
	if(start > r || end < l)
	{
		return 0;
	}
	if(lazytree[node])
	{
		Heads[node] = r-l + 1 - Heads[node];
		if(l != r)
		{
			lazytree[2*node] = !lazytree[2*node];
			lazytree[2*node+1] = !lazytree[2*node+1];
		}
		lazytree[node] = false;
	}
	if(l >= start && r <= end)
	{
		return Heads[node];
	}
	ll mid = getMid(l, r);
	return getHeads(l, mid, start, end, 2*node) + getHeads(mid+1, r, start, end, 2*node + 1);
}
void update(ll node, ll l, ll r, ll start, ll end)
{
	if(lazytree[node])
	{
		Heads[node] = r-l +1 - Heads[node];
		if(l != r)
		{
			lazytree[2*node] = !lazytree[2*node];
			lazytree[2*node+1] = !lazytree[2*node+1];
		}
		lazytree[node] = false;
	}
	if(start > r || end < l)
	{
		return;
	}
	if(l >= start && r <= end)
	{
		Heads[node] = r-l +1 - Heads[node];
		if(l != r)
		{
			lazytree[2*node] = !lazytree[2*node];
			lazytree[2*node+1] = !lazytree[2*node+1];
		}
	}
	else
	{
		ll mid = getMid(l, r);
		update(2*node, l, mid, start, end);
		update(2*node+1, mid+1, r, start, end);
		Heads[node] = Heads[2*node] + Heads[2*node+1];
	}
	
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	ll type, N, Q, A, B;
	cin >> N >> Q;
	for(ll i = 0; i < MAX; i++)
	{
		lazytree[i] = false;
		Heads[i] = 0;
	}
	while(Q--)
	{
		cin >> type >> A >> B;
		if(type)
		{
			cout << getHeads(0, N-1, A, B, 1) << endl;
		}
		else
		{
			update(1, 0, N-1, A, B);
		}
	}
	return 0;
}
