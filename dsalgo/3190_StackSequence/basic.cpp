//METHOD:
//1. monitor the process by recusion
//2. compute the Catalan number directly

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 

#define SIZE 20

int s[SIZE];
int ptr;
int num;

using namespace std;

void monitor(int n, int in_pos)
{
	//NOTICE: we can also output all stack sequences if necessary
	if(in_pos == n && ptr == 0)
	{
		num++;
		return; 
	}
	if(in_pos < n)
	{
		s[ptr++] = in_pos;
		monitor(n, in_pos+1);
		ptr--;
	}
	if(ptr > 0)
	{
		ptr--;
		monitor(n, in_pos);
		ptr++;
	}
}

int main()
{
	int n, i, j;
	cin>>n;
	ptr = 0;
	num = 0;
	monitor(n, 0);

	cout<<num<<endl;

	return 0;
}

