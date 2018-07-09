//
//  main.cpp
//  string
//
//  Created by mac on 2018/7/9.
//  Copyright © 2018年 mac. All rights reserved.
//

//标准库类型string
//表示可变长的字符序列，使用string类型必须首先包含string头文件
//string定义在命名空间std中
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //---定义和初始化string对象
    //如何初始化类的对象是由类本身决定的
    //一个类可以定义很多中初始化对象的方式（不同：初始值的数量不同，或者初始值的类型不同）
    string s1;//默认初始化，s1是一个空字符串
    cout << "s1 = " << s1 << endl;
    string s2 = s1;//s2是s1的副本，等价于string s2(s1);
    cout << "s2 = " << s2 << endl;
    string s3 = "hi";//s3是该字符串字面值的副本（除了字面值最后的那个空字符外）
    cout << "s3 = " << s3 << endl;//hi
    string s4(3, 'c');//s4的内容是ccc；把s4初始化为由连续n个字符c组成的串
    cout << "s4 = " << s4 << endl;//ccc
    
    //---直接初始化和拷贝初始化
    //使用等号（=）初始化一个变量：执行的是拷贝初始化，编译器把等号右侧的初始值拷贝到新创建的对象中去
    //不使用等号：执行的是直接初始化
    //当初始值只有一个时，使用拷贝或直接初始化
    //当有多个初始值时，使用直接初始化
    
    //---string对象上的操作
    //一个类除了要规定初始化其对象的方法外，还要定义对象上所能执行的操作
    //类既能定义通过函数名调用的操作，也能定义<<、+等各种运算符在该类对象上的新含义
    //1---读写string对象
    string s;//空字符串
    //在执行读取操作时，string对象会自动忽略开头的空白（空格符、换行符、制表符等），并从第一个真正的字符开始读起，直到遇见下一处空白为止
    cin >> s;//将string对象读入s，遇到空白停止；输入" hello world "
    cout << "s = " << s << endl;//输出hello
    //os << s---将s写到输出流os中，返回os
    //is >> s---从is中读取字符串赋给s，字符串以空白分隔，返回is
    //2---使用getline读取一整行
    //getline(is, s)---从is中读取一行赋给s，返回is
    //函数从给定的输入流中读取内容，直到遇到换行符为止（注意：换行符也被读进来了），然后把所读的内容存入到那个string对象中去（注意：不存换行符）
    //参数is---输入流
    //参数s---string对象
    //返回值---流参数
    string line;
    getline(cin, line);
    cout << "line = " << line << endl;
    //3---empty和size操作
    //s.empty()---s为空返回true，否则返回false
    string empty;
    cout << "empty = " << empty.empty() << endl;//1
    //s.size()---返回s中字符的个数
    //返回值---string::size_type类型的值
    //size_type：无符号类型的值，而且能足够放在任何string对象的大小
    string size = "hi";
    cout << "size = " << size.size() << endl;//2
    //4---比较string对象
    //s1 == s2---如果s1和s2中所含的字符完全一样，则它们相等；大小写敏感
    //s1 != s2
    //比较运算符<，<=，>，>=---利用字符在字典中的顺序进行比较，且对字母的大小写敏感
    //逐一比较string对象中的字符，并且对大小写敏感
    //字典顺序
    //顺序1---如果两个string对象的长度不同，而且较短string对象的每个字符都与较长string对象对应位置上的字符相同，就说较短string对象小于较长string对象
    //顺序2---如果两个string对象在某些对应的位置上不一致，则string对象比较的结果其实就是string对象中第一对相异字符比较的结果
    //5---为string对象赋值
    //s1 = s2---用s2的副本代替s1中原来的字符
    //6---两个string对象相加
    //s1 + s2---返回s1和s2连接后的结果
    //7---字面值和string对象相加
    //标准库允许把字符字面值和字符串字面值转换成string对象
    //必须确保加法运算符（+）的两侧的运算对象至少有一个是string
    
    //---处理string对象中的字符
    //使用范围for处理每个字符
    string str = "some";
    for(auto c : str){}//每次迭代，str的下一个字符被拷贝给c
    for(auto &c : str){}//把循环变量定义成引用类型，可以改变字符串中的字符
    //处理一部分字符
    //s[n]---返回s中第n个字符的引用，位置n从0计起
    //string对象的下标范围---[0, s.size()-1]
    
    return 0;
}
