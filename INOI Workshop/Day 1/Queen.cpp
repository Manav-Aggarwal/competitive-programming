#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
int main()
{
    ll test, k; cin >> test;
    for(k = 1; k <= test; k++)
	{
        ll C, D, V, i, denom;
        cin >> C >> D >> V;
        ll cnt = 0;
        ll maxM = 0;
        for(i = 0; i < D; i++) 
		{
            cin >> denom;
            while(denom > maxM + 1)
            {
                maxM = maxM + (ll)(C * (maxM + 1));
                cnt++;
            }
            maxM = maxM + (ll)(C * denom);
        }
        while(maxM < V)
        {
            maxM = maxM + (ll)(C * (maxM + 1));
            cnt++;
        }
        cout << "Case #" << k << ": " << cnt << endl;
    }
}
