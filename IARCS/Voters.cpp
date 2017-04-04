#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	int n1, n2, n3, i, k;
	cin >> n1 >> n2 >> n3;
	set<int> list1, list2, list3, final;
	set<int> :: iterator it;
	for(i = 0; i < n1; i++)
	{
		cin >> k;
		list1.insert(k);
	}
	for(i = 0; i < n2; i++)
	{
		cin >> k;
		list2.insert(k);
	}
	for(i = 0; i < n3; i++)
	{
		cin >> k;
		list3.insert(k);
	}
	for(it = list1.begin(); it != list1.end(); it++)
	{
		if(list2.count(*it) || list3.count(*it))
		{
			final.insert(*it);
		}
	}
	for(it = list2.begin(); it != list2.end(); it++)
	{
		if(list1.count(*it) || list3.count(*it))
		{
			final.insert(*it);
		}
	}
	for(it = list3.begin(); it != list3.end(); it++)
	{
		if(list1.count(*it) || list2.count(*it))
		{
			final.insert(*it);
		}
	}
	cout << final.size() << endl;
	for(it = final.begin(); it != final.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
