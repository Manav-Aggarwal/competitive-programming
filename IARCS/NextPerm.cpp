#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	while(K--)
	{
		vector<int> perm;
		perm.clear();
		for(int i = 0; i<N; i++)
		{
			int p;
			cin >> p;
			perm.push_back(p);
		}
		next_permutation(perm.begin(), perm.end());
		for(int j = 0; j<N;j++)
		{
			cout << perm[j] << " ";
		}
		cout << endl;
	}	
	return 0;
}
