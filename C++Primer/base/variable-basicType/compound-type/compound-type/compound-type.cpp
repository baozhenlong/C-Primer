//复合类型
//基于其他类型定义的类型
//一条声明语句由一个基本数据类型和紧随其后的一个声明符列表组成
//每个声明符命名了一个变量并指定该变量为与基本数据类型有关的某种类型
#include "stdafx.h"
#include <iostream>

int main()
{
	//---引用
	//引用为对象起了另外一个名字，引用类型引用另外一种类型
	//通过将声明符写成&d的形式来定义引用类型，其中d是声明的变量名
	//引用必须被初始化---因为无法令引用重新绑定到另外一个对象
	int ival = 11;
	int &refVal = ival;
	//定义引用时，程序把引用和它的初始值绑定在一起（不是拷贝）；一旦初始化完成，引用将和它的初始值对象一直绑定在一起
	//---引用即别名
	//引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字
	//定义了一个引用后，对其进行的所有操作都是在与之绑定的对象上进行的
	//因为引用本身不是一个对象，所以不能定义引用的引用
	refVal = 22;
	std::cout << "ival = " << ival << std::endl;//22
	std::cout << "refVal = " << refVal << std::endl;//22
	//---引用的定义
	//允许在一条语句中定义多个引用，其中每个引用标志符都必须以符号&开头
	//除了两种例外情况，其他所有引用的类型要和与之绑定的对象严格匹配
	//引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起
	int i2 = 22, i3 = 33;
	int &refVal2 = i2, r3 = i3, &refVal4 = i3;
	//refVal2, refVal4是一个引用，r3是int			

	//---指针										
	//解读：指向另外一种类型的复合类型；与引用一样，实现了对其它对象的间接访问
	//指针本身是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象
	//指针无须在定义时赋初值
	//和其他内置类型一样，在块作用域内定义的指针如果没有被初始化，也将拥有一个不确定的值
	//定义指针类型的方法---将声明符写成*d的形式，其中d是变量名
	//如果在一条语句中定义了几个指针变量，每个变量前面都必须有符号*
	
	int *ip1, ip2;
	//ip1是指向int型对象的指针；ip2是int型对象
	//---获取对象的地址
	//指针存放某个对象的地址，要想获取该地址，需要使用取地址符（操作符&）
	int *p = &ival;
	//p存放变量ival的地址；或者说p是指向变量ival的指针
	//因为引用不是对象，没有实际地址，所以不能定义指向引用的指针
	//除了两种例外情况，其他所有指针的类型都要和它所指向的对象严格匹配
	//---指针值（即地址）
	//1---指向一个对象
	//2---指向紧邻对象所占空间的下一个位置
	//3---空指针，意味着指向没有指向任何对象
	//4---无效指针，上述情况之外的其他值
	//试图拷贝或以其他方式访问无效指针的值都将引发错误
	//2,3没有指向任何具体对象				   
	//---利用指针访问对象
	//如果指针指向了一个对象，则允许使用解引用符（操作符*）来访问该对象
	std::cout << "*p = " << *p << std::endl;
	//由符号*得到指针p所指的对象，22						
	//对指针解引用会得出所指的对象，因此如果给解引用的结果赋值，实际上也就是给指针所指的对象赋值
	*p = 0;
	std::cout << "*p = " << *p << std::endl;//0
	std::cout << "ival = " << ival << std::endl;//0																			
	//解引用操作仅适用于那些确实指向了某个对象的有效的指针											
	//---空指针
	//空指针（不指向任何对象），在试图使用一个指针之前代码可以首先检查它是否为空
	//生成空指针的方法
	int *p1 = nullptr;//等价于int *p1 = 0
	//nullptr：一种特殊类型的字面值，它可以被转换成任意其他的指针类型
	int *p2 = 0;//直接将p2初始化为字面常量0
	int *p3 = NULL;//等价于int *p3 = 0
	//NULL：一个值为0的预处理变量
	//预处理变量：不属于命名空间std，由预处理器负责管理；当用到一个预处理变量时，预处理器会自动地将它替换为实际值
	//预处理器：运行编译过程之前的一段程序
	//把int变量的值0赋给指针是错误的操作
	//---赋值和指针
	//给指针赋值：就是令它存放一个新的地址，从而指向一个新的对象
	//赋值永远改变的是等号（=）左侧的对象
	//---其他指针操作
	//1---作为条件使用
	//只要指针拥有一个合法值，就能将它用在条件表达式中
	//任何非0指针对应的条件值都是true
	//2---比较指针
	//对于两个类型相同的合法指针，可以使用相等操作符（==）或不相等（!=）来比较它们，结果是布尔类型
	//两个指针存放的地址值相同（两个指针相同）的可能：
	//都为空
	//都指向同一个对象
	//都指向了同一个对象的下一地址	
	//注意：一个指针指向某对象，同时另一个指针指向另外对象的下一地址，此时也有可能相等

	//---void* 指针
	//void*是一种特殊的指针类型，可用于存放任意对象的地址
	//不能直接操作void*指针所指的对象

	//---理解复合类型的说明
	//变量的定义：包括一个基本数据类型和一组声明符
	//在同一条定义语句中，虽然基本数据类型只有一个，但是声明符的形式却可以不同；即一条定义语句可能定义出不同类型的变量
	int ivalue = 1, *pvalue = &ivalue, &rvalue = ivalue;
	//ivalue是一个int型的数；pvalue是一个int型指针；rvalue是一个int型引用

	//---指向指针的指针
	int *pi = &ivalue;//pi是指向一个int型的数
	int **ppi = &pi;//ppi是指向一个int型的指针
	std::cout << "ivalue = " << ivalue << std::endl;//1
	std::cout << "*pi = " << *pi << std::endl;//1
	std::cout << "**pi = " << **ppi << std::endl;//1
	//---指向指针的引用											
	//引用本身不是一个对象，因此不能定义指向引用的指针	
	//指针是对象，因此存在对指针的引用
	int *&rp = pi;//rp是一个对指针pi的引用
	//面对比较复杂的指针或引用的声明语句时，从右往左阅读，离变量名最近的符号，对变量的类型有最直接的影响

	return 0;
}

