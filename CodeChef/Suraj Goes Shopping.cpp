#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool wayToSort(int i, int j) {return (i > j);}
int main()
{	
	ios_base::sync_with_stdio(0);
	freopen("test.in", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int N, sum = 0, no = 1;
		cin >> N;
		vector<int> prices;
		for(int i = 0; i < N; i++)
		{
			int price;
			cin >> price;
			prices.push_back(price);
		}
		sort(prices.begin(), prices.end(), wayToSort);
		for(int i = 0; i  < prices.size();)
		{
			sum += prices[i];
			if(no == 1)
			{
				i++;no++;
			}
			else
			{
				no = 1;
				i += 3;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
