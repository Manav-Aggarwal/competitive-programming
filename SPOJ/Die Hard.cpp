/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while(t--)
	{
		ll H, A, time = 0, H1, H2, A1, A2;
		cin >> H >> A;
		bool inAir = true;
		H += 3;
		A += 2;
		while(true)
		{
			if(inAir)
			{
				H1 = H - 5;
				A1 = A - 10;
				H2 = H - 20;
				A2 = A + 5;
				if(H2 <= 0)
				{
					if(A1 <= 0 || H1 <= 0)
					{
						time++;
						break;
					}
					H = H1;
					A = A1;
				}
				else if(A1 <= 0 || H1 <= 0)
				{
					H = H2;
					A = A2;
				}
				else
				{
					H = H1;
					A = A1;
				}
			}
			else
			{
				H += 3;
				A += 2;
			}
			inAir = !inAir;
			time++;
		}
		cout << time << endl;
	}
	return 0;
}
