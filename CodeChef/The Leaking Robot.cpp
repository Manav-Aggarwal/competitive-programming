#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{	
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		int X, Y;
		cin >> X >> Y;
		bool b = false;
		if(X == 0 && Y == 0)
		{
			b = true;
			cout << "YES" << endl;
			continue;
		}		
		if(Y > 0)
		{
			if(!(Y&1))
			{
				if(X>= -Y && X < Y)
				{
					b = true;
					cout << "YES" << endl;
					continue;
				}
			}
		}
		if(Y < 0)
		{
			if(!(Y&1))
			{
				if(X>=Y && X <= -Y + 1)
				{
					b = true;
					cout << "YES" << endl;
					continue;
				}
			}
		}
		if(X < 0)
		{
			if(!(X&1))
			{
				if(Y >= X && Y <= -X)
				{
					b = true;
					cout << "YES" << endl;
					continue;
				}
			}
		}
		if(X > 0)
		{
			if(X&1)
			{
				if(Y >= -X + 1 && Y - 1 <= X )
				{
					b = true;
					cout << "YES" << endl;
					continue;
				}
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}
