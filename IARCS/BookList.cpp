#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        int M, N, pos, p, carry = 0;
        cin >> M;
        vector<int> books, borrow;
        for (int i = 0; i < M; i++)
        {
                int b;
                cin >> b;
                books.push_back(b);
        }
        cin >> N;
        for (int i = 0; i < N; i++)
        {
        	if(i==0)
        	{
        		cin >> p;
        		borrow.push_back(p-1);
        		cout << books[p-1]<< endl;
			}
    		else
			{
                cin >> p;
                sort(borrow.begin(), borrow.end());
                for(int j = 0; j<borrow.size(); j++)
                {
                	if(borrow[j] <= carry+p-1)
                	{
                		carry++;
					}
				}
				borrow.push_back(carry+p-1);
				cout << books[carry+p-1] << "\n";
				carry = 0;
				
			}
        }
        
        return 0;
}
