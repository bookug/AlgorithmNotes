/*=============================================================================
# Filename: multiples.cpp
# Author: Bookug Lobert 
# Mail: zengli-bookug@pku.edu.cn
# Last Modified: 2018-04-16 12:50
# Description: 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
=============================================================================*/

#include <iostream>
#include <sys/time.h> 

using namespace std;

//#define LIMIT 1000
//typedef int RESULT_TYPE;
#define LIMIT 1000000000
typedef long RESULT_TYPE;

long get_cur_time()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec*1000+tv.tv_usec/1000);
}

//EFFICIENCY: the % operator is costly
RESULT_TYPE naive_enumeration()
{
	RESULT_TYPE sum = 0;
	for(int i = 3; i < LIMIT; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	return sum;
}

//EFFICIENCY: the performance si worse than naive_enumeration()
RESULT_TYPE list_join()
{
	int target = LIMIT - 1;
	int size3 = target/3, size5 = target/5;
	int* list3 = new int[size3];
	int* list5 = new int[size5];
	for(int i = 0, j = 3; i < size3; ++i, j+=3)
	{
		list3[i] = j;
	}
	for(int i = 0, j = 5; i < size5; ++i, j+=5)
	{
		list5[i] = j;
	}
	//do intersection and sum
	int i = 0, j = 0;
	RESULT_TYPE sum = 0;
	while(i < size3 && j < size5)
	{
		if(list3[i] == list5[j])
		{
			sum += list3[i];
			i++;
			j++;
		}
		else if(list3[i] < list5[j])
		{
			sum += list3[i];
			i++;
		}
		else
		{
			sum += list5[j];
			j++;
		}
	}
	while(i < size3)
	{
		sum += list3[i];
		i++;
	}
	while(j < size5)
	{
		sum += list5[j];
		j++;
	}
	return sum;
}

RESULT_TYPE SumDivisibleBy(int n)
{
	int target = LIMIT - 1;
	RESULT_TYPE p = target / n;
	return n * p * (p+1) / 2;
}

//EFFICIENCY: thsi is very fast, no loop or recursion used
RESULT_TYPE math_compute()
{
	//3+6+9+12+......+999=3*(1+2+3+4+...+333)
	//5+10+15+...+995=5*(1+2+....+199)
	// note that 199=995/5 but also 999/5 rounded down to the nearest integer.
	// In many programming languages there exists a separate operator for that: div or \.
	// If we now also note that 1+2+3+...+p=½*p*(p+1) our program becomes:
	RESULT_TYPE sum = 0;
	sum = SumDivisibleBy(3) + SumDivisibleBy(5) - SumDivisibleBy(15);
	return sum;
}

int main()
{
	//the sum of all integers below 1000 won't exceed the capacity of int type
	RESULT_TYPE result = 0;
	long begin = get_cur_time();

	//result = naive_enumeration();
	result = list_join();
	//result = math_compute();

	long end = get_cur_time();
	cout<<result<<endl;
	cout<<"time: "<<(end-begin)<<" ms"<<endl;

	return 0;
}

