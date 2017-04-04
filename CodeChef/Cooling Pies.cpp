#include <bits/stdc++.h>
using namespace std;
bool wayToSort(int a, int b) {return (a > b); }
int main() 
{
	//freopen("test.in", "r", stdin);
    int T;
    cin >> T;
    while(T--)
    {
        long long int N, count = 0, i, j;
        cin >> N;
        int weights[N], limits[N];
        for(i = 0; i < N; i++)
        {
            cin >> weights[i];
        }
        for(i = 0; i < N; i++)
        {
            cin >> limits[i];
        }
        sort(weights, weights + N, wayToSort);
        sort(limits, limits + N, wayToSort);
        for(i = 0, j = 0; i < N && j < N;)
        {
            if(weights[i] <= limits[j])
            {
                count++;
                i++; j++;
            }
            else
            {
            	i++;
			}
        }
        cout << count << endl;
    }
    return 0;
}

