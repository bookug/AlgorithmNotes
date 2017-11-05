#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

bool isSubsequence(string s, string t)
{
	int slen = s.length(), tlen = t.length();
	int i = 0, j = 0, k;
	while(i < slen && j < tlen)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	if(i == slen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string s, t;

	while(cin>>s>>t)
	{
		if(isSubsequence(s, t))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}

	return 0;
}

