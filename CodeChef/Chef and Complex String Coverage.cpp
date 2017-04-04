#include <bits/stdc++.h>
using namespace std;
bool wayToSort(pair <int,int> i, pair <int,int> j) { return i.first > j.first; }
int strval(char a)
{
	return ((int) a) - 96;
}
int fromi(string S, int len, int i)
{
	int res = 0;
	if(i + len <= S.length() - 1)
	{
		while(len--)
		{
			res += strval(S[i]);
			i+=1;
		}
	}
	return res;
}
int isthere(vector<int> items, int k)
{
	for(int i = 0; i < items.size(); i++)
	{
		if(items[i]== k)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	//freopen("test.in", "r", stdin);
	string S;
	int N, D, strlen;
	cin >> S;
	cin >> N >> D;
	int lengths[N];
	for(int i = 0; i < N; i++)
	{
		cin >> lengths[i];
	}
	int prices[N];
	for(int i = 0; i < N; i++)
	{
		cin >> prices[i];
	}
	strlen = S.length();
	pair<int,int> maxT[strlen+1][strlen];
	for(int i = 0; i <= strlen; i++)
	{
		for(int j = 0; j < strlen; j++)
		{
			maxT[i][j] = make_pair(fromi(S, i, j), j);
		}
		sort(maxT[i], maxT[i] + strlen, wayToSort);
	}
	for(int i = 0; i <= strlen; i++)
	{
		for(int j = 0; j < strlen; j++)
		{
			cout << setw(2) << maxT[i][j].first << " ";
		}
		cout << endl;
	}
	
	
	int s, p, tmp, c = 0;
	int Table[N+1][D+1];
	int taken[N+1][D+1][2];
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= D; j++)
		{
			taken[i][j][0] = 0;
		}
	}
	for (s = 0; s <= N; s++)
	{
	   c = 0;
	   for (p = 0; p <= D; p++)
	   {
	   		if (s ==0|| p==0)
	        {Table[s][p] = 0;}
	        else if (prices[s-1] <= p)
			{		
	        		 tmp = maxT[lengths[s-1]][c].first+ Table[s-1][p-prices[s-1]];
	        		 if(tmp > Table[s-1][p])
	        		 {
	        		 	Table[s][p] = tmp;
	        		 	taken[s][p][0] = 1;
	        		 	int l = taken[s][p][1] = maxT[lengths[s-1]][c].second;
	        		 	if(taken[s][prices[s-1]][0] == 1)
	        		 		{
							 	c++;
							}
					 }
					 else
					 {
					 	Table[s][p] = Table[s-1][p];
					 }
			}
	        else
	                 Table[s][p] = Table[s-1][p];
	    }
	}
	cout << endl<< "-"<< " ";
	for(int j = 0; j <=D; j++)
	{
		cout << setw(2) << j << " ";
	}
	cout << endl;
	for(int i = 0; i <= N; i++)
	{
		cout << i << " ";
		for(int j = 0; j <= D; j++)
		{
			cout << setw(2) << Table[i][j] << " ";
		}
		cout << endl;
	}
	cout << Table[N][D];
	cout << endl;
	vector<int> items;
	vector<int> indexes;
	int j = D;
	for (int i = N; i>= 1; i--) {
	    if (taken[i][j][0] == 1) {
	        items.push_back(i-1);
	        indexes.push_back(taken[i][j][1]);
	        j -= prices[i-1];
	    }
	}
	reverse(items.begin(),items.end());
	int d = 0;
	for(int k = 0; k < N; k++)
	{
		if(find(items.begin(),items.end(), k) == items.end())
		{
			cout << -1 << " ";
		}
		else
		{
			cout << indexes[d] << " ";
			d++;
		}
	}
	
	return 0;
}
