#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long int arr[100001];
set<long long int> indexp[6];
long long int n, m, i, choice, l, r, p, d, j, lower, upper, ind;
set<long long int>::iterator it, itlow, itup;
vector<long long int>:: iterator di;
vector<long long int> del;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i]%2 == 0)
		{
			indexp[2].insert(i);
		}
		if(arr[i]%3 == 0)
		{
			indexp[3].insert(i);
		}
		if(arr[i]%5 == 0)
		{
			indexp[5].insert(i);
		}
	}
	cin >> m;
	while(m--)
	{
		cin >> choice;
		if(choice == 1)
		{
			cin >> l >> r >> p;
			l--; r--;
			itlow = lower_bound(indexp[p].begin(), indexp[p].end(), l);
			for(it = itlow; it!=indexp[p].end() ; it++)
			{
				ind = *it;
				if(ind > r) {break;}
				arr[ind] /=p;
				if(arr[ind] % p)
				{
					del.push_back(ind);
				}
			}
			for(di = del.begin(); di!= del.end();di++)
			{
				indexp[p].erase(*di);
			}
			del.clear();
		}
		else
		{
			cin >> l >> d;
			l--;
			if(arr[l]%2 == 0)
			{
				indexp[2].erase(l);
			}
			if(arr[l]%3 == 0)
			{
				indexp[3].erase(l);
			}
			if(arr[l]%5 == 0)
			{
				indexp[5].erase(l);
			}
			if(d % 2 == 0)
			{
				indexp[2].insert(l);
			}
			if(d % 3 == 0)
			{
				indexp[3].insert(l);
			}
			if(d % 5 == 0)
			{
				indexp[5].insert(l);
			}
			arr[l] = d;
		}
	}
	for(i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
