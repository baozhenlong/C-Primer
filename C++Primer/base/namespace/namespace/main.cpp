//
//  main.cpp
//  namespace
//
//  Created by mac on 2018/7/9.
//  Copyright © 2018年 mac. All rights reserved.
//

//命名空间的using声明
//作用域操作符（::）---含义：编译器应从操作符左侧名字所示的作用域寻找右侧那个名字
//std::cin---使用命名空间std中的名字cin
#include <iostream>

//---using声明
//using namespace::name;//可以直接访问该命名空间中的名字
using std::cout;
//每个名字都需要独立的using声明；按照规定，每个using声明引入命名空间中的一个成员
using std::endl;

//---头文件不应包含using声明
//位于头文件的代码，一般来说不应该使用using声明，这是因为头文件的内容会拷贝到所有引用它的文件中去

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n" << endl;//cout和std::cout含义相同
    return 0;
}
