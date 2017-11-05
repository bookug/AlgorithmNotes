#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

#define SIZE 1000005
int NEXT[SIZE];

//In unoptimized kmp-NEXT array, only the 0-th ele is -1(so move 0-(-1)=1 step, we must move forward in each loop!)
//However, in the optimized one, other eles can also be -1
//NOTICE: we should include the final element's longest prefix-suffix pattern(which is not included in KMP)
void computeNext(string s)
{
	int i = 0, len = s.length(), k = -1;
	NEXT[0] = -1;
	while(i < len)
	{
		while(k >= 0 && s[k] != s[i])
		{
			k = NEXT[k];
		}
		i++;
		k++;
		//this is unoptimized method
		NEXT[i] = k;
		//NOTICE: below is for optimized method
		//if(s[k] == s[i])
		//{
			//NEXT[i] = NEXT[k];
		//}
		//else
		//{
			//NEXT[i] = k;
		//}
	}
	//for(i = 0; i <= len; ++i)
	//{
		//cout<<NEXT[i]<<" ";
	//}cout<<endl;
}

int main()
{
	int n, num = 0;
	string s;

	while(cin>>n)
	{
		if(n == 0)
		{
			break;
		}
		num++;
		cin>>s;
		//compute the NEXT array(unoptimized), the optimized one maybe not keep the longest prefix-suffix pattern
		computeNext(s);
		cout<<"Test case #"<<num<<endl;
		for(int i = 2; i <= n; ++i)
		{
			if(i % (i - NEXT[i]) == 0)
			{
				int k = i / (i - NEXT[i]);
				if(k > 1)
				{
					cout<<i<<" "<<k<<endl;
				}
			}
		}
		cout<<endl;
	}

	return 0;
}

