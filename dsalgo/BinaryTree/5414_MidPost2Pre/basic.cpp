//METHOD: 
//1. find the root in the mid-sequence and divide the whole into left and right in each loop, to build the original 
//binary tree and then do a pre-order traversal
//2. find root and output directly, deal with left subtree before right subtree

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

void traversal(vector<int>& seq, int mid_left, int mid_right, int post_left, int post_right)
{
	//cout<<mid_left<<" "<<mid_right<<" "<<post_left<<" "<<post_right<<endl;
	int root = seq[post_right];
	cout<<root<<" ";
	if(mid_left == mid_right)
	{
		return; 
	}
	//search the root in mid-sequence
	int i = 0;
	//BETTER: if we use a map<ID, pos>, then the whole complexity is O(nlgn) instead of O(n*n)
	for(i = mid_left; i <= mid_right; ++i)
	{
		if(seq[i] == root)
		{
			break;
		}
	}
	if(i > mid_left)
	{
		traversal(seq, mid_left, i-1, post_left, post_left+i-1-mid_left);
	}
	if(i < mid_right)
	{
		traversal(seq, i+1, mid_right, post_right-mid_right+i, post_right-1);
	}
}

int main()
{
	int n, num;
	vector<int> seq;
	while(cin>>num)
	{
		seq.push_back(num);
	}
	n = seq.size() / 2;

	traversal(seq, 0, n-1, n, 2*n-1);

	return 0;
}

