/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int getSum(int *fenwickTree, int n, int index)
{
	int sum = 0;
	index++;
	while(index > 0)
	{
		sum += fenwickTree[index];
		index -= index & (-index);
	}
	return sum;
}
void updateTree(int *fenwickTree, int n, int index, int val)
{
	index++;
	while(index <= n)
	{
		fenwickTree[index] += val;
		index += index & (-index);
	}
}
int *buildTree(int arr[], int n)
{
	int *fenwickTree = new int[n+1];
	for(int i = 1; i <= n; i++)
	{
		fenwickTree[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		updateTree(fenwickTree, n, i, arr[i]);
	}
	return fenwickTree;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int arr[] = {20, 10, 50, 40};
	int *fenwickTree = buildTree(arr, 4);
	cout << getSum(fenwickTree, 4, 0);
	return 0;
}
