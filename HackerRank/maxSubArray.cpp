#include <bits/stdc++.h>
using namespace std;
int FindMaxSubArray(int array[], int N)
{	
	int max_sofar = array[0];
	int max_end = array[0];
	for(int i = 1; i < N; i++)
	{
		max_end = max(array[i], max_end + array[i]);
		max_sofar =  max(max_end, max_sofar);
	}
	return max_sofar;
}
int main()
{
	//freopen("test.in", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int N, nonCont = 0;
		cin >> N;
		int array[N];
		for(int i = 0; i < N; i++)
		{
			cin >> array[i];
		}
		for(int i = 0; i < N; i++)
		{
			if(array[i] > 0)
			{
				nonCont+=array[i];
			}
		}
		if(nonCont == 0)
		{
			nonCont = array[0];	
		}
		cout << FindMaxSubArray(array, N) << " " << nonCont << endl;
	}
return 0;
}
