/*=============================================================================
# Filename:		LargestPrimeFactor.cpp
# Author: Bookug Lobert 
# Mail: zengli-bookug@pku.edu.cn
# Last Modified:	2018-04-17 13:57
# Description: 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
=============================================================================*/

//NOTICE:
//Special care is also required when adding a great many numbers so that the sum of those 
//numbers exceeds the 32 bit signed integer limit or when multiplying two numbers whose 
//product exceeds that limit.  (using typecast in each language)

#include <iostream>
#include <sys/time.h> 
#include <math.h> 

using namespace std;

typedef long RESULT_TYPE;

long get_cur_time()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec*1000+tv.tv_usec/1000);
}

RESULT_TYPE naive_enumerate(long num, long limit)
{
	long maxi = 1;
	//when i is a factor it will necessarily be prime, as all smaller factors have been removed
	for(long i = 2; i <= limit; ++i)
	{
		while(num % i == 0)
		{
			num /= i;
			maxi = i;
		}
	}
	if(num > maxi)
	{
		maxi = num;
	}
	return maxi;
}

//EFFICIENCY: thsi is faster than naive_enumerate()
RESULT_TYPE enumerate_odd(long num, long limit)
{
	long maxi = 1;
	// 2 is the only even prime, so if we treat 2 separately we can increase factor with 2 every step
	if(num % 2 == 0)
	{
		while(num % 2 == 0)
		{
			num /= 2;
		}
		maxi = 2;
	}
	//when i is a factor it will necessarily be prime, as all smaller factors have been removed
	for(long i = 3; i <= limit; i+=2)
	{
		while(num % i == 0)
		{
			num /= i;
			maxi = i;
		}
	}
	if(num > maxi)
	{
		maxi = num;
	}
	return maxi;
}

//EFFICIENCY: this is much faster than naive_enumerate() and enumerate_odd()
RESULT_TYPE enumerate_sqrt(long num, long limit)
{
	long maxi = 1;
	// 2 is the only even prime, so if we treat 2 separately we can increase factor with 2 every step
	if(num % 2 == 0)
	{
		while(num % 2 == 0)
		{
			num /= 2;
		}
		maxi = 2;
	}
	//when i is a factor it will necessarily be prime, as all smaller factors have been removed
	for(long i = 3; i <= limit; i+=2)
	{
		while(num % i == 0)
		{
			num /= i;
			maxi = i;
		}
		//every number n can at most have one prime factor greater than sqrt(n)
		limit = sqrt(num);
	}
	if(num > maxi)
	{
		maxi = num;
	}
	return maxi;
}

int main()
{
	//The number 600851475143 you were asked to factor is larger than 2^31-1=2147483647
	//optional types: long, long long, int64, _int64
	//If you declared your variable in that way it might also be necessary to place a suffix 
	//after the number like 600851475143L
	long num = 0;
	cin>>num;
	RESULT_TYPE result = 2;
	long begin = get_cur_time();

	//NOTICE: the smallest prime factor can not be larger than limit, but the largest prime factor may be lower than limit
	long limit = sqrt(num);
	//result = naive_enumerate(num, limit);
	//result = enumerate_odd(num, limit);
	result = enumerate_sqrt(num, limit);

	long end = get_cur_time();
	cout<<result<<endl;
	cout<<"time: "<<(end-begin)<<" ms"<<endl;

	return 0;
}

