//METHOD:
//1. 模拟法：使用循环链表，复杂度为O(mn) (其中m取余后不会超过n)
//2. 递归法：寻找递归公式
//http://blog.sina.com.cn/s/blog_4d8f3f920101ebpd.html
//https://baike.baidu.com/item/%E7%BA%A6%E7%91%9F%E5%A4%AB%E9%97%AE%E9%A2%98#5
//3. 递归法基础上改造而成的迭代法 
//
//TIPS:
//1. 若在模拟法中使用数组(marked as visited or unvisited)而非循环链表，复杂度为O(n^2)
//2. which method can output the sequence?

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	list<int> vlist;
	for(int i = 0; i < n; ++i)
	{
		vlist.push_back(i);
	}
	list<int>::iterator cur = vlist.begin();
	while(vlist.size() > 1)
	{
		int k = vlist.size();
		int pos = (m-1) % k;
		for(int i = 0; i < pos; ++i)
		{
			cur++;
			if(cur == vlist.end())
			{
				cur = vlist.begin();
			}
		}
		cur = vlist.erase(cur);
		if(cur == vlist.end())
		{
			cur = vlist.begin();
		}
	}
	
	cout<<vlist.front()+1<<endl;
	
	return 0;
}

