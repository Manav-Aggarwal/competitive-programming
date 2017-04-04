#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXA 111111
ll chains[22222], cnt[MAXA];
int main()  
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--)  
	{
	    ll n, m, i, cuts = 0, end, len, freq, donuts;
	    for(i = 0; i < MAXA; i++)
	    {
	    	cnt[i] = 0;
		}
	    cin >> n >> m;
	    end = m;
	    for(i = 0; i < m; i++)    
		{
	        cin >> chains[i];
	        cnt[chains[i]]++;
	    }
	    if(n == m)   
		{
	        cout << m/2 << endl;
	        continue;
	    }
	    sort(chains, chains+m);
	    i = 0;
	    while(end != 1 && i < m-1)   
		{
	        len = chains[i];
	        freq = cnt[len];
	        donuts = min (freq, (ll)(end-1)/(len+1));
	        end -= (donuts* (len+1));
	        cuts += len*donuts;
	        if(donuts < freq)  
	        {
	        	break;
			}
	        i += donuts;
	    }
	    cuts += end-1;
	    cout << cuts << endl;
    }
    return 0;
}
