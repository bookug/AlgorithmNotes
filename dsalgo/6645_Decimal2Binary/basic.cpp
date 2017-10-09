//METHOD: notice that the decimal number can be too large to be represented by long long
//1. iterative: %2 and divided by 2 (big-integer division)
//http://blog.sina.com.cn/s/blog_7393daaf0100sutp.html
//2. split 10^n into a combination of 2^m, and sum the coefficient, finally %2 /2 to adjust it
//3. transfer all digits and 10^n to representtation of 2's addition and multiplication, and compute
//
//if change binary number to decimal, then use 1010 isntead of 10
//This method also works well when changing n-radix number to m-radix number

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 

using namespace std;

#define SIZE 500

int a[SIZE], b[SIZE];

int bigIntDivideTwo(int* in, int len, int* out)
{
	int i = 0, j = 0, k = 0;
	while(i < len)
	{
		k = k * 10 + in[i];
		if(k >= 2 || j > 0)
		{
			out[j++] = k / 2;
		}
		k = k % 2;
		i++;
	}
	//cout<<"check result: "<<endl;
	//for(i = 0; i < j; ++i)
	//{
		//cout<<out[i];
	//}
	//cout<<endl;

	//NOTICE: here we can get the remaining of the whole, which can be used as the result of %
	//when the radix > 2, we can not get the remaining of the whole directly by the rightmost digit
	return j;
}

int main()
{
	vector<int> result;
	int i, j, k;
	string str;
	cin>>str;
	int len = str.length();
	for(int i = 0; i < len; ++i)
	{
		a[i] = str[i] - '0';
	}

	int *in = a, *out = b, *tmp = NULL;
	while(true)
	{
		//NOTICE: for binary number, we can check if even just by the smallest digit
		k = in[len-1] % 2;
		result.push_back(k);
		len = bigIntDivideTwo(in, len, out);
		if(len == 0)
		{
			break;
		}
		tmp = in;
		in = out;
		out = tmp;
	}

	k = result.size();
	for(j = k-1; j >= 0; --j)
	{
		cout<<result[j];
	}
	cout<<endl;
	
	return 0;
}

