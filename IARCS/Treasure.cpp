// Treasure.cpp
/* Author - Manav Aggarwal */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M, T, S, p, tmptoken, tmpmachine, x , y, d = 0;;
	long long int N;
	cin >> M >> T >> S >> N;
	int prod = M*T;
	vector<vector<int> > matrix(prod+1,(vector<int>(2))); /* To store the machines and token numbers */
	for(int i = 1; i <= prod; i++) /* Stores the corresponding token and machine */
	{
		cin >> matrix[i][0];
		cin >> matrix[i][1];
	}
	int m = S-1, token = 1;
	M-=1;
	if(N<=(prod)) /* If N is smaller than or equal to the total no. of machines and tokens(M*T) */
	{
		for(long long int j = 0; j<N; j++)
		{
			p = m+1; /* record the machine number */
			int temp = (m*T) + token; /* m is the machine which outputs the token or the machine number when token is inserted into it */
			token = matrix[temp][0], m = matrix[temp][1]-1; /* 0 is the token and 1 is the machine number to go to next */
		}
		cout << p; /* print the Nth machine number */
	}
	else /* If N is greater than the total no. of machines and tokens(M*T) */
	{
		for(int j = 0; j < prod; j++)  /* j is the index of the number from which the loop starts */
		{
			tmptoken = matrix[m*T + token][0], tmpmachine = matrix[m*T + token][1]-1;
			token = tmptoken, m = tmpmachine; /* get next token*/
			for(int k = 0; k<prod-j; k++)
			{
				x = tmpmachine*T + tmptoken;
				if(matrix[tmpmachine*T + tmptoken][0] == token && matrix[tmpmachine*T + tmptoken][1]-1 == m) // check if this line has been visited before
				{
					k=k+1; /* k is the length of the loop. Once the programs reaches its end it starts again from j. Since k was 0 it needs to be increased.*/
					j=j+1; /* j is increased so that the it is eqaual to the starting point of the loop */
					N = (N-j) % k; /* the part from 0 to j runs only once so it is subtracted from N and since the program now enters the loop whose length is equal to k, the difference is divided by k and N is set to the remainder */
					if(N == 0) /* if the remainder is 0 then we can return the starting machine number of the loop which is equal to tmpmachine*/
					{
						cout << tmpmachine +1;
						return 0;
					}
					for(d = 0; d < N; d++ ) /* If the remainder is 0 then we need to output the Nth machine visited in the loop of length k*/
					{
						y = m+1; /* record the machine number */
						int temp = (m*T) + token;
						token = matrix[temp][0], m = matrix[temp][1]-1;
					}
					cout << y; /* output the machine number */
					return 0;
				}
				tmpmachine = matrix[x][1]-1, tmptoken = matrix[x][0]; /* get next token to compare */
			}
		}
	}
	return 0;
}
