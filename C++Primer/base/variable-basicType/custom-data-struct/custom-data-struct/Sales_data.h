//
//  Sales_data.h
//  custom-data-struct
//
//  Created by mac on 2018/7/5.
//  Copyright © 2018年 mac. All rights reserved.
//

//---编写自己的头文件
//为了确保各个文件中类的定义一致，类通常被定义在头文件中，而且类所在头文件的名字应与类的名字一样
//头文件：通常包含那些只能被定义一次的实体（如类、const、constexpr变量）
//头文件经常用到其他头文件的功能，有必要在书写头文件时做适当处理，使其遇到多次包含的情况也能安全和正常工作
//头文件一旦改变，相关的源文件必须重新编译以获取更新过的声明

//---预处理器概念
//确保头文件多次包含仍能安全工作的常用技术是预处理器
//预处理器：是在编译之前执行的一段程序
//当预处理器看到#include标记时，就会用指定的头文件的内容代替#include
//头文件保护符，依赖于预处理变量
//预处理变量无视C++语言中关于作用域的规则；一般把预处理变量的名字全部大写
//预处理变量的两种状态：已定义和未定义
//#define指令---把一个名字设定为预处理变量
//检查某个指定的预处理变量是否已经定义
//#ifdef指令---当且仅当变量已定义时为真
//#ifndef指令---当且仅当变量未定义时为真
//一旦检查结果为真，则执行后续操作，直至遇到#endif指令为止
//当检查结果为假，则忽略#ifdef（或#ifndef）到#endif之间的部分
//#endif指令

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

//类
//Sales_data---类名
//{}---类体；可以为空；类内部定义的名字必须唯一，但是可以与类外部定义的名字重复
//;---必不可少；表示声明符（通常为空）的结束
struct Sales_data {
    //类数据成员---类的成员
    //类的数据成员定义了类的对象的具体内容，每个对象有自己的一份数据成员拷贝；修改一个对象的数据成员，不会影响其他Sales_data的对象
    //类的数据成员的定义方法和定义普通变量一样：一个基本类型+一个或多个声明符
    std::string bookNo;//默认初始化为空字符串
    unsigned units_sold = 0;
    double revenue = 0.0;
    //每个Sales_data对象都将包括这3个数据成员
    //C++新标准规定，可以为数据成员提供一个类内初始值
    //创建对象时，类内初始值将用于初始化数据成员；没有初始值的成员将被默认初始化
};

#endif /* Sales_data_h */