/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b, c, x, y, num1, num2, product1, product2, i, sum = 0, cpyProduct2;
	vector<ll> products, num1s, num2s;
	set<ll> digits, added;
	bool noZero;
	for(a = 1; a <= 9; a++)
	{
		for(b = 1; b <= 9; b++)
		{
			while(b == a)
			{
				b++;
			}
			for(c = 1; c <= 9; c++)
			{
				while(c == b || c == a)
				{
					c++;
				}
				for(x = 1; x <= 9; x++)
				{
					while(x == a || x == b || x == c)
					{
						x++;
					}
					for(y = 1; y <= 9; y++)
					{
						while(y == a || y == b|| y == c || y == x)
						{
							y++;
						}
						num1 = a*100 + b*10 + c; num2 = x*10 + y;
						product1 = num1 * num2; product2 = (a*1000 + b*100 + c*10 + x) * y;
						cpyProduct2 = product2;
						noZero = true;
						if(product1 >= 1234 && product1 <= 9876)
						{
							digits.clear();
							digits.insert(a); digits.insert(b); digits.insert(c); digits.insert(x); digits.insert(y);
							while(product1)
							{
								digits.insert(product1%10);
								if(product1%10 == 0)
								{
									noZero = false;
								}
								product1/=10;
							}
							if(digits.size() == 9 && noZero)
							{
								num1s.push_back(num1);
								num2s.push_back(num2);
								products.push_back(num1*num2);
							}
						}
						noZero = true;
						if(product2 >= 1234 && product2 <= 9876)
						{
							digits.clear();
							digits.insert(a); digits.insert(b); digits.insert(c); digits.insert(x); digits.insert(y);
							while(product2)
							{
								digits.insert(product2%10);
								if(product2 % 10 == 0)
								{
									noZero = false;
								}
								product2 /= 10;
							}
							if(digits.size() == 9 && noZero)
							{
								num1s.push_back(a*1000 + b*100 + c*10 + x);
								num2s.push_back(y);
								products.push_back(cpyProduct2);
							}
						}
					}
				}
			}
		}
	}
	
	for(i = 0; i < products.size(); i++)
	{
		if(added.count(products[i]))
		{
			i++;
			continue;
		}
		cout << num1s[i] << " * " << num2s[i] << " = " << products[i] << endl;
		added.insert(products[i]);
		sum+= products[i];
	}
	cout << "Sum: " << sum;
	return 0;
}
