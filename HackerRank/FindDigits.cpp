#include <iostream>
using namespace std;
int FindDigits(int num);
int main() 
{
    int noOfTestCases;
    cin >> noOfTestCases;
    int array[noOfTestCases];
    for(int i = 0; i<noOfTestCases; i++)
    {
        cin >> array[i];
    }
    for(int j=0;j<noOfTestCases;j++)
    {
        FindDigits(array[j]);
    }
    return 0;
}
int FindDigits(int num) 
{
    int n = num;
    int digit, count = 0;
    do
    {
          digit = num % 10; 
          if (digit == 1) {count++;}
          else if (digit>0 && n%digit == 0 )
          {
              count++;
          }
          num/=10;
         } while (num > 0);
    cout << count << endl;
    return 0;
}

