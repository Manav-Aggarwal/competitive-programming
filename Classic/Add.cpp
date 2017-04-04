#include <iostream>
using namespace std;
int add(int x, int y);
int main()
{
    int input1,input2,answer;
    cin >> input1 >> input2;
    answer = add(input1, input2);
    cout << answer;
   return 0;
}
int add(int x, int y)
{
    int carry;
    while (y!=0)
    {
        carry = x & y;
        x = x^y;
        y = carry << 1;
    }
    return x;
}
