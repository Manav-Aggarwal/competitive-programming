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
int query(int *fenwickTree1, int *fenwickTree2, int n, int index)
{
	return query(fenwickTree1, n, index)*index - query(fenwickTree2, n, index);
}
int query(int *fenwickTree1, int *fenwickTree2, int n, int a, int b)
{
	return query(fenwickTree1, fenwickTree2, n, b) - query(fenwickTree1, fenwickTree2, n, a-1);
}
void updateTree(int *fenwickTree, int n, int index, int val)
{
	while(index <= n)
	{
		fenwickTree[index] += val;
		index += index & (-index);
	}
}
void updateTree(int *fenwickTree1, int *fenwickTree2, int n, int a, int b, int val)
{
	updateTree(fenwickTree1, n, a, val);
	updateTree(fenwickTree1, n, b+1, -val);
	updateTree(fenwickTree2, n, a, val*(a-1));
	updateTree(fenwickTree2, n, b+1, -val*b);
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int arr1[] = {0, 0, 0, 0, 0};
	int arr2[] = {0, 0, 0, 0, 0};
	updateTree(arr1, arr2, 5, 1, 3, 2);
	updateTree(arr1, arr2, 5, 3, 4, 2);
	updateTree(arr1, arr2, 5, 1, 4, 10);
	cout << query(arr1, arr2, 5, 1, 4);
	return 0;
}
