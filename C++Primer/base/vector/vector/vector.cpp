//标准库类型vector（容器）
//表示对象的集合，其中所有对象的类型都相同
//集合中的每个对象都有一个与之对应的索引，索引用于访问对象
#include "stdafx.h"
#include <iostream>

#include <vector>
using std::vector;
//C++既有类模板，也有函数模板
//vector是一个类模板
//模板本身不是类或函数，可以将模板看作为编译器生成类或函数编写的一份说明
//编译器根据模板创建类或函数的过程称为实例化，当使用模板时，需要指出编译器应把类或函数实例化成何种类型

int main()
{
	//---定义和初始化vector对象
	//vector<T> v1
	//v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
	//vector<T> v2(v1)
	//v2中包含v1所有元素的副本；等价于vector<T> v2 = v1
	//1---创建指定数量的元素
	//vector<T> v3(n, val)
	//v3包含了n个重复的元素，每个元素的值都是val
	//vector<T> v4(n)
	//v4包含了n个重复地执行了值初始化的对象
	//值初始化
	//通常情况下，可以只提供vector对象容纳的元素数量而不用略去初始值；此时库会创建一个值初始化的元素初值，并把它赋给容器中的所有元素；这个初始值由vector对象中元素的类型决定
	//int---0
	//类类型---由类默认初始化
	//2---列表初始化vector对象
	//vector<T> v5{a, b, c...}
	//v5包含了初始值个数的元素，每个元素被赋予相应的初始值；等价于vector<T> v5 = {a, b, c...}
	//使用拷贝初始化时（=），只能提供一个初始值
	//如果提供的是一个类内初始值，则只能使用=或使用{}的形式初始化
	//如果提供的是初始元素值列表，则只能把初始值都放在{}里进行列表初始化，而不能放在()里
	//3---列表初始值还是元素数量
	vector<int> v1(10);
	//v1有10个元素，每个的值都是0
	vector<int> v2{ 10 };
	//v2有1个元素，该元素的值是10
	vector<int> v3(10, 1);
	//v3有10个元素，每个的值都是1
	vector<int> v4{ 10, 1 };
	//v4有2个元素，值分别是10和1
	//()---提供的值用来构造vector对象
	//{}---列表初始化该vector对象

	//---vector操作
	//返回for语句体内不应改变其遍历序列的大小
	//v.empty()---如果v不含有任何元素，返回真；否则返回假
	//v.size()---返回v中元素的个数
	//返回值的类型---vector<int>::size_type
	//v.push_back(t)---向v的尾端添加一个值为t的元素
	//v[n]---返回v中第n个位置上元素的引用
	//v1 = v2---用v2中元素的拷贝替换v1中的元素
	//v1 = {a, b, c...}---用列表中元素的拷贝替换v1中的元素
	//v1 == v2---当且仅当它们的元素数量相同，且对应位置的元素值都相同
	//v1 != v2
	//比较运算符<，<=，>，>=---以字典顺序进行比较

    return 0;
}

