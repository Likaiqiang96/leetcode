#include "iostream"
using namespace std;
//难点在于：
//    不适用超过32位的数值进行溢出判断，只能在过程中判断
//数学方法
int main()
{
	int x;
	int temp,res=0;
	cin >> x;
    //最大值可以使用 INT_MAX 
	cout << INT_MAX << endl;
    //数值反转的思路就是 不断 对10 取余 ，除以10 
    //结果 是 左移 + 余数
	while (x != 0)//整数反转的循环条件是不为0，每次循环小10 倍
	{
		temp = x % 10;
		x /= 10;
		if (res > 214748364 || (res == 214748364 && temp > 7))
		{
			return 0;
		}
		if (res <- 214748364 || (res == -214748364 && temp < -8))
		{
			return 0;
		}
		res = res * 10 + temp;
	}
	cout << "test " << res << endl;
	return 0;
}

//方法2  string 容器
//未在leetcode测试，因为reverse报错
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int x;
	int temp,res=0;
	cin >> x;
	cout << "x: "<< x << endl;
	string s;
	//数值转字符串
	//x = INT_MAX;
	s = to_string(x);
	//字符串反转
	reverse(s.begin(), s.end());
	//判断输入是否合法
	if (s.size() > 10)
	{
		return 0;
	}
	else if (s.size() == 10)
	{
		//作者给出的是用字符串比较大小，直接从字符串上进行判断
		//https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-han-wu-ji-1-pnfd/
		if (x > 0 && s >= "2147483647") return 0; 
		//注意此处，负值的边界不同，符号的处理
		if (x < 0 && s >= "2147483648") return 0;
	}
	//stoi、 atoi 的区别：
	//stoi的入口参数是string ，atoi 入口是 char
	//stoi 带溢出检测，超出返回错误，atoi超出返回边界值
	//stoi的自己实现 T8
	cout << "res: " << (x > 0? stoi(s):-1*stoi(s)) << endl;
	
	return 0;
}