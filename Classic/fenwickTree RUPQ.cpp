/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int query(int *fenwickTree, int n, int index)
{
	int sum = 0;
	while(index > 0)
	{
		sum += fenwickTree[index];
		index -= index & (-index);
	}
	return sum;
}
void updateTree(int *fenwickTree, int n, int index, int val)
{
	while(index <= n)
	{
		fenwickTree[index] += val;
		index += index & (-index);
	}
}
void updateTree(int *fenwickTree, int n, int a, int b, int val)
{
	updateTree(fenwickTree, n, a, val);
	updateTree(fenwickTree, n, b+1, -val);
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int arr[] = {0, 0, 0, 0, 0};
	updateTree(arr, 5, 1, 3, 2);
	updateTree(arr, 5, 3, 4, 2);
	cout << query(arr, 5, 3);
	return 0;
}
