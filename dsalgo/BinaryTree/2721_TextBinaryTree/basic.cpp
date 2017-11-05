//METHOD: the text representation of the binary tree is just a DFS traversal
//If a node has only right child, then the left child be represented by "*"
//(if only has left child, then no need to store --* for right, because later there will be a node of a lower level)
//Otherwise, if a node has no child, none child will be represented in the input

//QUERY: why the text representation can determine the binary tree?
//Because it is a DFS traversal, and we can use the program below to rebuild the binary tree it corresponds to.
//(there is no ambiguity)

#include <iostream>
#include <stdio.h>
#include <vector>
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
int num;

void preTraversal(int id)
{
	cout<<tree[id].text;
	if(tree[id].left > 0)
	{
		preTraversal(tree[id].left);
	}
	if(tree[id].right > 0)
	{
		preTraversal(tree[id].right);
	}
}

void midTraversal(int id)
{
	if(tree[id].left > 0)
	{
		midTraversal(tree[id].left);
	}
	cout<<tree[id].text;
	if(tree[id].right > 0)
	{
		midTraversal(tree[id].right);
	}
}

void postTraversal(int id)
{
	if(tree[id].left > 0)
	{
		postTraversal(tree[id].left);
	}
	if(tree[id].right > 0)
	{
		postTraversal(tree[id].right);
	}
	cout<<tree[id].text;
}

void output()
{
	if(num == 0)
	{
		cout<<endl<<endl<<endl;
	}
	else
	{
		preTraversal(0);
		cout<<endl;
		postTraversal(0);
		cout<<endl;
		midTraversal(0);
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int t;
	string s;
	cin>>t;

	while(t--)
	{
		memset(tree, -1, sizeof(tree));
		num = 0;
		//NOTICE: The level of a node can be represented by the size of stack
		stack<int> path;
		while(cin>>s)
		{
			if(s == "0")
			{
				break;
			}
			//build the tree
			int level = s.length() - 1;
			if(s[level] != '*')
			{
				tree[num].text = s[level];
				num++;
			}

			while((int)(path.size())-1 >= level)
			{
				path.pop();
			}
			if(!path.empty())
			{
				int father = path.top();
				int flag = (s[level] == '*')?0:num-1;
				//NOTICE: here we use -1 to indicate that if this child's value has been assigned
				if(tree[father].left == -1)  //left child
				{
					tree[father].left = flag;
				}
				else                         //right child
				{
					tree[father].right = flag;
				}
			}
			path.push(num-1);
		}
		output();
	}

	return 0;
}

