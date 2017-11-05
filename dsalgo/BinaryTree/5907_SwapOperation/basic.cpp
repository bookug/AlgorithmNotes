//METHOD: 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

#define SIZE 105

class Node
{
public:
	int left;
	int right;
	int father;
}tree[SIZE];

void swapNode(int x, int y)
{
	//NOTICE: that xf and yf can be the same, and they can not be 0(no ancestor-child relation!)
	int xf = tree[x].father;
	int yf = tree[y].father;
	bool x_is_left = true, y_is_left = true;
	if(tree[xf].right == x)
	{
		x_is_left = false;
	}
	if(tree[yf].right == y)
	{
		y_is_left = false;
	}
	if(x_is_left)
	{
		tree[xf].left = y;
	}
	else
	{
		tree[xf].right = y;
	}
	if(y_is_left)
	{
		tree[yf].left = x;
	}
	else
	{
		tree[yf].right = x;
	}
	tree[y].father = xf;
	tree[x].father = yf;
}

//BETTER: thsi can be changed to iteration, or kept with each node(needing updating)
void findLeftMost(int x)
{
	if(tree[x].left == -1)
	{
		cout<<x<<endl;
	}
	else
	{
		findLeftMost(tree[x].left);
	}
}

int main()
{
	int t, n, m, i, j, k, op, x, y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i = 0 ; i < n; ++i)
		{
			cin>>k>>x>>y;
			tree[k].left = x;
			if(x != -1)
			{
				tree[x].father = k;
			}
			tree[k].right = y;
			if(y != -1)
			{
				tree[y].father = k;
			}
		}
		while(m--)
		{
			cin>>op>>x;
			if(op == 1)
			{
				cin>>y;
				swapNode(x, y);
			}
			else
			{
				findLeftMost(x);
			}
		}
	}

	return 0;
}

