#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N, count = 0;
	cin >> N;
	int array[N];
	for(int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	sort(array, array + N);
	int smallest = array[0];
	while(smallest !=0 )
	{
		for(int i = 0; i < N; i++)
		{
			if(array[i] > 0)
			{
				array[i] -= smallest;
				count ++;
			}	
		}
		cout << count << endl;
		count = 0;
		smallest = 0;
		for(int j = 0; j< N; j++)
		{
			if(smallest < array[j])
			{
				smallest = array[j];
				break;
			}
		}
	}
	return 0;
}
