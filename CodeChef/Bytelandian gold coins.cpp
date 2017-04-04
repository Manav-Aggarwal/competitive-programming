#include <bits/stdc++.h>
using namespace std;
long long int amt;
long long Optimal[1000001];
long long int max(long long a, long long b) {return (a > b) ? a : b;}
long long int getamt(long long int a)
{
    if(a <= 1000000)
    {
         return Optimal[a];
    }
    else
    {
        return max(a, getamt(a/2) + getamt(a/3) + getamt(a/4));
    }
}
void init()
{
    long long int sum, i;
    for(i = 0; i < 12; i++)
    {
        Optimal[i] = i;
    }
    for(i = 12; i < 1000001; i++)
    {
        sum = Optimal[i/2] + Optimal[i/3] + Optimal[i/4];
        Optimal[i] = max(sum, i);
    }
}
int main() {
	init();
	while(scanf("%lld",&amt) != EOF)
	{
	   cout << getamt(amt) << endl;
	}
	return 0;
}
