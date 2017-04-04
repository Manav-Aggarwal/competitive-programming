/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

string makeLargestPerm(ll num1)
{
	ll arr[10], i;
	string temp = "";
	for(i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	while(num1)
	{
		arr[num1%10]++;
		num1/=10;
	}
	for(i = 9; i >= 0; i--)
	{
		while(arr[i]--)
		{
			temp+= char(i + '0');
		}
	}
	return temp;
}

bool wayToSort(pair<string, ll> f, pair<string, ll> s){return f.first > s.first;}
const int M = 10000;
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("output.out", "w", stdout);
	ll i, j;
	vector<pair<string, ll> > perms;
	for(i = 345; i < M-1; i++)
	{
		perms.push_back(make_pair(makeLargestPerm(i*i*i), i));
	}
	sort(perms.begin(), perms.end(), wayToSort);
	for(i = 0; i < perms.size() - 4; i++)
	{
		if(perms[i].first == perms[i+1].first && perms[i].first == perms[i+2].first && perms[i].first == perms[i+3].first && perms[i].first == perms[i+4].first)
		{
			cout << perms[i].second << " " << perms[i+1].second  <<  " " << perms[i+2].second  <<  " " << perms[i+3].second  <<  " " << perms[i+4].second << endl;
		}
	}
	return 0;
}
