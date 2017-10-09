//METHOD:
//1. transfer Infix Expression to Suffix Expression, and then compute value using stack
//If the number contains '.', then we can also deal with it.
//TODO: we may need to deal with such cases: -7*3  (just add 0 before - if the former character is an operator)
//
//NOTICE: only Infix Expression can guarantee the unique expression tree, and the value is ensured
//(as well as Prefix Expression or Postfix Expression)
//However, we must need infix traversal and prefix/postfix traversal to ensure a binary tree
//Explain: In Infix expression, the () can ensure the structure. While in Prefix Expression or Postfix Expression,
//the order has no ambiguous meanings because the special characters: + x - /  
//(they all have two operators which must be binded with them)
//(the Postfix Expression must be valid, i.e., it must be equivalent to an Infix Expression)
//(In addition, operator x and / are prior to + and -)
//
//Question: can we calculate the Infix Expression directly without Postfix Expression?

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

#define SIZE 600
map<char, int> prior;
//NOTICE: we must set a divider between numbers to avoid all digits messed up
char divid = ',';

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
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
			if(i == len-1 || !isDigit(s[i+1]))
			{
				ret += divid;
			}
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
	int len = s.length(), i = 0, tmp;
	while(i < len)
	{
		if(isDigit(s[i]))
		{
			tmp = s[i++] - '0';
			while(isDigit(s[i]))
			{
				tmp = tmp * 10 + s[i++] - '0';
			}
			//NOTICE: here s[i] must be the divider
			i++;
			//cout<<"push "<<tmp<<endl;
			ans.push(tmp);
		}
		else //operator: + - x /
		{
			int op2 = ans.top();
			ans.pop();
			int op1 = ans.top();
			ans.pop();
			tmp = calculate(op1, op2, s[i]);
			//cout<<"push op: "<<tmp<<endl;
			ans.push(tmp);
			i++;
		}
	}

	return ans.top();
}

int main()
{
	int n, i, j;
	cin>>n;
	string s;
	//Infact, ')' can not occur in stack
	prior['+'] = prior['-'] = 0; prior['*'] = prior['/'] = 1; prior['('] = prior[')'] = -1;

	while(n--)
	{
		cin>>s;
		s = Infix2Post(s);
		//cout<<s<<endl;
		cout<<compute(s)<<endl;
	}

	return 0;
}

