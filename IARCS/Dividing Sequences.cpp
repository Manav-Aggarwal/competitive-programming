/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
int main()
{       
        ios_base::sync_with_stdio(false); cin.tie(0);
        ll n, i, j, size, maxSize = 0;
        cin >> n;
        ll arr[n], longest[n];
        for(i = 0; i < n; i++)
        {
        	cin >> arr[i];
        }
        //Dynamic Programming yay!!!
        longest[0] = 1;
        for(i = 1; i < n; i++)
        {
        	size = 1;
        	for(j = 0; j < i; j++)
        	{
        		if(arr[i]%arr[j] == 0)
        		{
        			size = max(size, longest[j]+1);
				}
			}
			longest[i] = size;
			maxSize = max(size, maxSize);
		}
		cout << maxSize;
        return 0;
}
