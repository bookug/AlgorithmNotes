//METHOD: 
//1. find the root in the mid-sequence and divide the whole into left and right in each loop, to build the original 
//binary tree and then do a post-order traversal
//2. find root and output directly, deal with left subtree before right subtree
//NOTICE: each node's label is unique, otherwise there may be ambiguity

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

void traversal(string preSeq, string midSeq, int preLeft, int preRight, int midLeft, int midRight)
{
	char root = preSeq[preLeft];
	//if(midLeft == midRight)
	//{
		//return; 
	//}
	//search the root in mid-sequence
	int i = 0;
	//BETTER: if we use a map<ID, pos>, then the whole complexity is O(nlgn) instead of O(n*n)
	for(i = midLeft; i <= midRight; ++i)
	{
		if(midSeq[i] == root)
		{
			break;
		}
	}
	if(i > midLeft)
	{
		traversal(preSeq, midSeq, preLeft+1, i+preLeft-midLeft, midLeft, i-1);
	}
	if(i < midRight)
	{
		traversal(preSeq, midSeq, preRight-midRight+i+1, preRight, i+1, midRight);
	}
	cout<<root;
}

int main()
{
	string preSeq, midSeq;
	while(cin>>preSeq)
	{
		cin>>midSeq;
		int n = preSeq.size();
		traversal(preSeq, midSeq, 0, n-1, 0, n-1);
		cout<<endl;
	}

	return 0;
}

