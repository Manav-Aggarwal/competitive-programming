#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("test.in", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int A[100000];
		set<int> s;
		int N, mx = 0, mxp;
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			int pile;
			cin >> pile;
			if(s.count(pile-1) == 0)
			{
				A[pile-1] = 0;
			}
			A[pile-1] += 1;
			s.insert(pile-1);
		}
		for (set<int>::iterator it=s.begin(); it!=s.end(); ++it)
		{
			int p = *it;
			if(A[p] > mx)
			{
				mx = A[p];
				mxp = p;
			}
		}
		cout << N - mx << endl;
	}
	return 0;
}
