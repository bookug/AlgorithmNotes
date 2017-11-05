//METHOD: in the expression tree, each operator has exactly 2 operands

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 
#include <string.h> 
#include <queue> 

using namespace std;

#define SIZE 50
int m[26];
map<char, int> prior;
class Node
{
public:
	Node* left;
	Node* right;
	Node* father;
	char c;
	Node()
	{
		this->c = ' ';
		this->left = this->right = this->father = NULL;
	}
	Node(char _c, Node* _left = NULL, Node* _right = NULL)
	{
		this->c = _c;
		this->left = _left;
		this->right = _right;
		this->father = NULL;
	}
};
Node* root = NULL;
char buffer[SIZE*2][SIZE*2];

bool isDigit(char c)
{
	return c >= 'a' && c <= 'z';
}

string Infix2Post(string s)
{
	int len = s.length();
	string ret = "";
	stack<char> op;
	for(int i = 0; i < len; ++i)
	{
		if(isDigit(s[i]))
		{
			ret += s[i];
		}
		else if(s[i] == '(')
		{
			op.push(s[i]);
		}
		else if(s[i] == ')')
		{
			while(!op.empty())
			{
				char c = op.top();
				op.pop();
				if(c == '(')
				{
					break;
				}
				ret += c;
			}
		}
		else //operator: + - x /
		{
			while(!op.empty())
			{
				char c = op.top();
				if(prior[c] < prior[s[i]])
				{
					break;
				}
				op.pop();
				ret += c;
			}
			op.push(s[i]);
		}
	}

	while(!op.empty())
	{
		ret += op.top();
		op.pop();
	}
	return ret;
}

int calculate(int op1, int op2, char op)
{
	int ret;
	switch(op)
	{
		case '+':
			ret = op1 + op2;
			break;
		case '-':
			ret = op1 - op2;
			break;
		case '*':
			ret = op1 * op2;
			break;
		case '/':
			ret = op1 / op2;
			break;
		default:
			cout<<"ERROR!"<<endl;
			break;
	}
	return ret;
}

int compute(string s)
{
	stack<int> ans;
	stack<Node*> tree;
	int len = s.length(), i = 0, tmp;
	while(i < len)
	{
		if(isDigit(s[i]))
		{
			ans.push(m[s[i]-'a']);
			Node* numPtr = new Node(s[i]);
			tree.push(numPtr);
		}
		else //operator: + - x /
		{
			int op2 = ans.top();
			ans.pop();
			int op1 = ans.top();
			ans.pop();
			tmp = calculate(op1, op2, s[i]);
			ans.push(tmp);
			Node* right = tree.top();
			tree.pop();
			Node* left = tree.top();
			tree.pop();
			Node* father = new Node(s[i], left, right);
			left->father = father;
			right->father = father;
			tree.push(father);
		}
		i++;
	}

	root = tree.top();
	return ans.top();
}

void freeTree(Node* root)
{
	if(root == NULL)
	{
		return; 
	}
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

int findRootPosition(Node* root)
{
	if(root->left == NULL)
	{
		return 0;
	}
	return findRootPosition(root->left) + 2;
}

//TODO: a*b+c/d+a
//what should the leaves be output
int outputTree(Node* root, int y, int x)
{
	buffer[y][x] = root->c;
	int h = 1;
	if(root->left != NULL)
	{
		buffer[y+1][x-1] = '/';
		buffer[y+1][x+1] = '\\';
		int leftH = outputTree(root->left, y+2, x-2);
		int rightH = outputTree(root->right, y+2, x+2);
		h += max(leftH, rightH);
	}
	return h;
}

//NOTICE: in the post-expression, all leaves are ordered from left to right
void output(string post)
{
	//the leftmost leaf's position is 0, so find the root's position
	int position = findRootPosition(root);
	//NOTICE: use a output buffer to control output
	memset(buffer, ' ', sizeof(buffer));
	int h = outputTree(root, 0, position);
	h = 2 * h - 1;
	for(int i = 0; i < h; ++i)
	{
		for(int j = 2*SIZE-1; j >= 0; --j)
		{
			if(buffer[i][j] != ' ')
			{
				buffer[i][j+1] = '\0';
				break;
			}
		}
		cout<<buffer[i]<<endl;
	}
	//release the tree
	freeTree(root);
}

int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	char c;
	int v;
	while(n--)
	{
		cin>>c>>v;
		m[c-'a'] = v;
	}

	prior['+'] = prior['-'] = 0; prior['*'] = prior['/'] = 1; prior['('] = prior[')'] = -1;
	string post = Infix2Post(s);
	cout<<post<<endl;
	int ans = compute(post);
	output(post);
	cout<<ans<<endl;

	return 0;
}

