#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 

using namespace std;

void transfer(string& s)
{
	int len = s.length();
	for(int i = 0; i < len; ++i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			int k = s[i] - 'a';
			k = (k + 1) % 26;
			s[i] = k + 'a';
		}
		else if(s[i] >= 'A' && s[i] <= 'Z')
		{
			int k = s[i] - 'A';
			k = (k + 1) % 26;
			s[i] = k + 'A';
		}
	}
}

int main()
{
	int n, i, j;
	cin>>n;
	string s;
	cin.get();
	//or getchar();
	while(n--)
	{
		//NOTICE: here we must read the whole line which may contains spaces
		getline(cin, s);
		//COMPARE: getline(for string class) and cin.getline(str,len) will skip the \n, while cin and cin.get() won't 
		transfer(s);
		cout<<s<<endl;
	}

	return 0;
}

