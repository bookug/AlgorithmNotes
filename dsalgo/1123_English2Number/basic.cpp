#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string> 
#include <stack> 
#include <map> 

using namespace std;

//NOTICE: the values is in [-999999999, 999999999], which can be represented by int type
map<string, int> value;

int recursive_function(vector<int>& sv, int left, int right)
{
	if(left == right)
	{
		return sv[left];
	}
	int i, j, k;
	int maxe = sv[left], maxi = left;
	for(i = left+1; i <= right; ++i)
	{
		if(sv[i] > maxe)
		{
			maxe = sv[i];
			maxi = i;
		}
	}

	int val1 = 1;
	if(left <= maxi-1)
	{
		val1 = recursive_function(sv, left, maxi-1);
	}
	int val2 = 0;
	if(maxi+1 <= right)
	{
		val2 = recursive_function(sv, maxi+1, right);
	}
	int ans = val1 * maxe + val2;
	return ans;
}

//NOTICE: keywords are separated by spaces
//we must do it recursively, first found the largest unit and then divide and conquer
void transfer(string str)
{
	int ans = 0, len = str.length(), i = 0, factor = 1, j, prev = -1, curr, tmp = 1;
	if(str.substr(0, 8) == "negative")
	{
		factor = -1;
		i = 9;
	}
	vector<int> sv;
	while(i < len)
	{
		j = i+1;
		while(j < len && str[j] != ' ')
		{
			j++;
		}
		curr = value[str.substr(i,j-i)];
		sv.push_back(curr);

		while(j < len && str[j] == ' ')
		{
			j++;
		}
		i = j;
	}
	
	ans = recursive_function(sv, 0, sv.size()-1);
	cout<<factor * ans<<endl;
}

int main()
{
	string str;
	value["zero"] = 0; value["one"] = 1; value["two"] = 2; value["three"] = 3; value["four"] = 4; value["five"] = 5;
	value["six"] = 6; value["seven"] = 7; value["eight"] = 8; value["nine"] = 9; value["ten"] = 10; value["eleven"] = 11;
	value["twelve"] = 12; value["thirteen"] = 13; value["fourteen"] = 14; value["fifteen"] = 15; value["sixteen"] = 16;
	value["seventeen"] = 17; value["eighteen"] = 18; value["nineteen"] = 19; value["twenty"] = 20; value["thirty"] = 30;
	value["forty"] = 40; value["fifty"] = 50; value["sixty"] = 60; value["seventy"] = 70; value["eighty"] = 80;
	value["ninety"] = 90; value["hundred"] = 100; value["thousand"] = 1000; value["million"] = 1000000;

	while(true)
	{
		getline(cin, str);
		//NOTICE: getline will skip the "\n" or "\r\n", and not add it to the string or input buffer
		if(str == "")
		{
			break;
		}
		transfer(str);
	}

	return 0;
}

