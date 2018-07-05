//
//  main.cpp
//  handle-type
//
//  Created by mac on 2018/7/5.
//  Copyright © 2018年 mac. All rights reserved.
//

//处理类型
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //---类型别名
    //类型别名：是一个名字，它是某种类型的同义词；和类型的名字等价
    //1---使用typeof
    typedef double wages;//wages是double的同义词
    typedef wages base, *p;//base是double的同义词，p是double*的同义词
    //2---使用using别名声明
    using dd = double;
    //---指针、常量和类型别名
    typedef char *pstring;//char*的别名；pstring是指向char的指针，其基本数据类型是指针
    const pstring cstr = 0;//cstr是指向char的常量指针
    const pstring *ps;//ps是一个指针，它指向的对象是指向char的常量指针
    const char *tempcstr = 0;//指向常量的指针，其基本数据类型是const char，*成了声明符的一部分
    
    //---auto类型说明符（C++11新标准）
    //auto让编译器通过初始值来推算变量的类型，显然auto定义的变量必须有初始值
    //使用auto在一条语句中声明多个变量
    //因为一条声明语句只有有一个基本数据类型，所以该语句中所有变量的初始基本数据类型都必须一样
    auto i = 0, *pi = &i;//正确：i是整数，p是整型指针
    //auto sz = 0, pi = 3.14;//错误：sz和pi的类型不一致
    //---复合类型、常量和auto
    //编译器推断出来的auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则
    //以引用对象的类型作为auto的类型
    int ival = 0, &r = i;
    auto a = r;//a是一个整数
    //auto一般会忽略掉顶层const，同时底层const则会保留下来
    const int ci = i, &cr = ci;
    auto b = ci;//b是一个整数，ci的顶层const特性被忽略掉了
    auto c = cr;//c是一个整数，cr是ci的别名，ci本身是一个顶层const
    auto d = &i;//d是一个整型指针（整数的地址就是指向整数的指针）
    auto e = &ci;//e是一个指向整数常量的指针（对常量对象取地址是一种底层const）
    //希望推断出的auto类型是一个顶层const，需明确指出
    const auto f = ci;//f是const int
    //将引用的类型设为auto，此时原来的初始化规则仍然适用
    auto &g = ci;//g是一个整型常量引用，绑定到ci
    //auto &h = 22;//错误：不能为非常量引用绑定字面值
    const auto &j = 42;//正确：可以为常量引用绑定字面值
    
    //---decltype类型说明符（C++11新标准）
    //作用：选择并返回操作数的数据类型；在此过程中，编译器分析表达式并得到它的烈性，却不实际计算表达式的值
    //decltype(变量)---返回该变量的类型
    //---decltype和引用
    //decltype((变量))---返回引用类型；(变量)是一个表达式，变量是一种可以作为赋值语句左值的特殊表达式，这样的decltype会得到引用类型
    //decltype(表达式)---返回表达式结果对应的类型
    
    
    return 0;
}
