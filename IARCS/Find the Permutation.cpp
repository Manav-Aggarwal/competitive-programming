/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
int main()
{       
        ios_base::sync_with_stdio(false); cin.tie(0);
        ll n, i; 
        cin >> n;
        ll inversions[n+1], next;
        list<ll> seq;
        queue<ll> toChange;
        for(i = 1; i <= n; i++)
        {
                cin >> inversions[i];
                if(inversions[i] > 0)
                {
                        toChange.push(i);
                }
                else
                {
                        seq.push_front(i);
                }
        }
        while(!toChange.empty())
        {
                next = toChange.front();
                toChange.pop();
                for(list<ll>::iterator it = seq.begin(); it != seq.end(); it++)
                {
                        if(*it < next)
                        {
                                inversions[next]--;
                        }
                        if(inversions[next] == 0)
                        {
                                seq.insert(++it, next);
                                break;
                        }
                }
        }
        for(list<ll>::reverse_iterator it = seq.rbegin(); it != seq.rend(); it++)
        {
                cout << *it << " ";
        }
        return 0;
}
