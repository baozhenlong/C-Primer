//
//  main.cpp
//  iterator
//
//  Created by mac on 2018/7/9.
//  Copyright © 2018年 mac. All rights reserved.
//

//迭代器
//所有标准库容器都可以使用迭代器
//类似于指针类型，迭代器也提供了对对象的间接访问
//有效的迭代器或者指向某个元素，或者指向容器中尾元素的下一位置；其他情况都属于无效
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //---使用迭代器
    //有迭代器的类型同时拥有返回迭代器的成员
    //v.begin()---返回指向第一个元素的迭代器
    //v.end()---返回指向尾元素的下一位置（尾后迭代器）
    //如果容器为空，则begin和end返回的是同一个迭代器（尾后迭代器）
    
    //---迭代器运算符
    //*iter---返回迭代器iter所指元素的引用
    //iter->mem---解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem
    //++iter---令iter指示容器中的下一个元素
    //--iter---令iter指示容器中的上一个元素
    //iter1 == iter2---判断两个迭代器是否相等，如果两个迭代器指示的是同一个元素或者它们是同一个容器的尾后迭代器，则相等；反之，不相等
    //iter1 != iter2
   
    //---迭代器类型
    vector<int>::iterator it;//it能读写vector<int>的元素
    string::iterator it2;//it2能读写string对象中的字符
    vector<int>::const_iterator it3;//it3只能读元素，不能写元素
    string::const_iterator it4;//it4只能读字符，不能写字符
    
    //---begin和end运算符
    //begin和end返回的具体类型由对象是否是常量决定；如果对象是常量，返回const_iterator；不是，则返回iterator
    vector<int> v;
    const vector<int> cv;
    auto it_1 = v.begin();//it_1的类型是vector<int>::iterator
    auto it_2 = cv.begin();//it_2的类型是vector<int>::const_iterator
    //为了便于专门得到const_iterator类型的返回值，C++11新标准引入了两个函数：cbegin()和cend()
    auto it_3 = v.cbegin();//it_3的类型是vector<int>::const_iterator
    
    //---结合解引用和成员访问操作
    //(*it).mem
    //解引用迭代器可获得迭代器所指的对象，如果该对象的类型恰好是类，就有可能进一步访问它的成员
    //it->mem
    //箭头运算符（->）把解引用和成员访问两个操作结合在一起
    
    //---某些对vector的操作会使迭代器失效
    //不能在范围for循环中向vector对象添加元素
    //任何一种可能改变vector对象容量的操作，比如push_back，都会使该vector对象的迭代器失效
    //谨记：但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素
    
    //---迭代器运算
    //1---vector和string迭代器支持的运算
    //iter + n---
    //iter - n---
    //iter += n---
    //iter -= n---
    //iter1 - iter2---
    //关系运算符>，>=，<，<=---
    
    return 0;
}
