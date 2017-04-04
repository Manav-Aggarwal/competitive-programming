// Angry Children.cpp
/* Author - Manav Aggarwal */
#include <iostream>
#include <algorithm>
using namespace std;
int ComputeUnfairness(unsigned long long int array[], int N, int K); 
/*Declare function**/
int main() {
    unsigned long long int N, K, unfairness;
    cin >> N >> K;
    unsigned long long int candies[N];
    for (int i=0; i<N; i++) 
	/*Store inputs in an array*/
    { 
        cin >> candies[i];
    }
    unfairness = ComputeUnfairness(candies, N, K); /*Calls the function*/
    cout << unfairness << "\n";
    return 0;
}
    
int ComputeUnfairness(unsigned long long int array[], int N, int K)
{
    sort(array, array + N); 
	/*Sort the given array*/
    unsigned long long int unfairness = array[N-1]; 
	/* Since unfairness has to be minimized, we take it to be the biggest value in the array(sorted) */
    for (int i = 0; i<N; i++) 
	/* loop N times */
    {
        if(i+K <= N) 
		/* i+K is the distance between max and min*/
        {
        	if(unfairness > array[i+K-1] - array[i] ) 
			/* Compare, if unfairness is bigger than the difference of the two values. If yes, replace its value with the smaller one */
        	{
        		unfairness = array[i+K-1] - array[i];
			}
        }
    }
    return unfairness; 
	/* return the minimized value */
}
