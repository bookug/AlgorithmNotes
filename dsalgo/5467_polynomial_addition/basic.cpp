//METHOD:
//use map<int,int> will be easier

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef struct MyItem
{
	int coeff;
	int power;
}Item;
bool operator<(const Item& a, const Item& b)
{
	return a.power < b.power;
}

void remove_duplicate(vector<Item>& data)
{
	sort(data.begin(), data.end(), less<Item>());
	vector<Item> newdata;
	int size = data.size(), i, j;
	for(i = 0; i < size;)
	{
		for(j = i+1; j < size; ++j)
		{
			if(data[j].power != data[i].power)
			{
				break;
			}
			data[i].coeff += data[j].coeff;
		}
		//WARN: here we must check!
		if(data[i].coeff != 0)
		{
			newdata.push_back(data[i]);
		}
		i = j;
	}
	data = newdata;
}

void polynomial_addition(vector<Item>& data1, vector<Item>& data2)
{
	vector<Item> result;
	remove_duplicate(data1);
	remove_duplicate(data2);
	//merge 2 vectors by scanning
	int size1 = data1.size(), size2 = data2.size();
	int i, j;
	Item tmp;
	i = 0; j = 0;
	while(i < size1 && j < size2)
	{
		int cmp = data1[i].power - data2[j].power;
		if(cmp == 0)
		{
			tmp.power = data1[i].power;
			tmp.coeff = data1[i].coeff + data2[j].coeff;
			if(tmp.coeff != 0)
			{
				result.push_back(tmp);
			}
			i++; j++;
		}
		else if(cmp < 0)
		{
			result.push_back(data1[i]);
			i++;
		}
		else //>
		{
			result.push_back(data2[j]);
			j++;
		}
	}
	while(i < size1)
	{
		result.push_back(data1[i]);
		i++;
	}
	while(j < size2)
	{
		result.push_back(data2[j]);
		j++;
	}
	//output result in descending order of power
	int size = result.size();
	for(i = size - 1; i >= 0; --i)
	{
		cout<<"[ "<<result[i].coeff<<" "<<result[i].power<<" ] ";
	}
	cout<<endl;
}

int main()
{
	int n, i, j, k;
	cin>>n;
	Item tmp;

	while(n--)
	{
		vector<Item> data1;
		vector<Item> data2;
		while(true)
		{
			cin>>tmp.coeff>>tmp.power;
			if(tmp.power < 0)
			{
				break;
			}
			if(tmp.coeff != 0)
			{
				data1.push_back(tmp);
			}
		}
		while(true)
		{
			cin>>tmp.coeff>>tmp.power;
			if(tmp.power < 0)
			{
				break;
			}
			if(tmp.coeff != 0)
			{
				data2.push_back(tmp);
			}
		}
		polynomial_addition(data1, data2);
	}
	
	return 0;
}

