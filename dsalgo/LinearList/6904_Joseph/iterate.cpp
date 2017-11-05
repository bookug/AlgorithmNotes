//METHOD:
//1. 模拟法：使用循环链表，复杂度为O(mn)
//2. 递归法：寻找递归公式  O(n)
//http://blog.sina.com.cn/s/blog_4d8f3f920101ebpd.html
//https://baike.baidu.com/item/%E7%BA%A6%E7%91%9F%E5%A4%AB%E9%97%AE%E9%A2%98#5
//3. 递归法基础上改造而成的迭代法 O(n)
//
//0,1,...m-1, m, m+1,...,n-1
//0,1,...m-2, m, m+1,...,n-1
//m,m+1,...,n-1, 0,1,...,m-2
//0,1,...,..............,n-2
//f(n,m)=(f(n-1,m)+m) mod n   (m<n, notice that n is variable)

#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	
	int f = 0; //i = 1
	for(int i = 2; i <= n; ++i)
	{
		int j = m % i;
		f = (f + j) % i;
	}
	cout<<f+1<<endl;
	
	return 0;
}

