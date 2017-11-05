//METHOD: use Huffman tree
//1. we can build the huffman tree, and then sum the count of each leaf
//2. we can sum the element's value when each element is popped from the queue, but not build the tree
//QUERY: why the Huffman tree is the best?

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 
#include <string.h> 

using namespace std;

#define SIZE 105

//root is id 0
class Node
{
public:
	int left;
	int right;
	char text;
}tree[SIZE];

int main()
{
	int n, x;
	priority_queue< int, vector<int>, greater<int> > qq;
	cin>>n;
	while(n--)
	{
		cin>>x;
		qq.push(x);
	}

	int sum = 0;
	while(qq.size() > 1)
	{
		int t = qq.top();
		qq.pop();
		t += qq.top();
		qq.pop();
		qq.push(t);
		sum += t;
	}
	cout<<sum<<endl;

	return 0;
}

