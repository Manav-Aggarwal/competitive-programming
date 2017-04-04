// ACM_ICPC.cpp
/* Author - Manav Aggarwal */
#include <iostream>
using namespace std;
int main()
{
	int n, m, c, max = 0, r = 0;
	cin >> n >> m;
	string array[n];
	for(int k = 0; k < n; k++)
	{
		cin >> array[k];
		/* Take Input*/
	}
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			c = 0;
			for (int k = 0; k<m; k++)
			{
				if(array[i][k] == '1' || array[j][k] == '1') 
				/* if characters of any of the string is 1, both know the topic */
				{
					c++; /* increase count of topics known */
				}	
			}
			if (c > max) 
			{
				max = c; 
				/* Store maximum number of topics a team can know in max*/
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			c = 0;
			for(int k = 0; k <m; k++)
			{
				if(array[i][k] == '1' || array[j][k] == '1') 
				{
					c++;
				}
			}
			if(c == max) 
			/* Count no of teams that know maximum no. of topics*/
			{
				r++;
			}
		}
	}
	cout << max << endl << r; /* output max and maximum number of teams (r)*/
	return 0;
}

