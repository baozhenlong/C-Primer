
//---注释
//1---单行注释
//2---界定符对注释（多行注释）
//注释界定符不能嵌套
/*   main.cpp
 *   brief-introduction
 *
 *   Created by mac on 2018/7/4.
 *   Copyright © 2018年 mac. All rights reserved.
 */

//基础介绍
#include <iostream>

//打印输入
void printInput();

//一个简单的C++程序
//每个C++程序都包含一个或多个函数，其中一个必须命名为main；操作系统通过调用main来运行C++程序
int main(int argc, const char * argv[]) {
    // insert code here...
    //main函数的返回类型必须为int
    std::cout << "Hello, World!\n";
    printInput();
    return 0;
}

//---函数（function）---具名的计算单元
//1---返回类型（return type）---函数返回值的类型
//2---函数名（function name）---用来进行函数调用
//3---形参列表（parameter list）---允许为空；指出调用函数时可以使用什么样的实参
//4---函数体（function body）---语句块，定义了函数所执行的动作

//---输入和输出
//C++并未定义任何输入输出（IO）语句，取而代之，包含一个全面的标准库来提供IO机制
//iostream库包含2个基础类型（istream、ostream）和4个IO对象（cin、cout、cerr、clog）
//istream---输入流
//ostream---输出流
//cin---istream类型的对象：从标准输入读取数据
//cout---ostream类型的对象：将数据写入到标准输出，通常用于程序的正常输出内容
//cerr---ostream类型的对象：关联到标准错误，通常写入到与标准输出相同的设备；默认情况下，写到cerr的数据不缓冲的；用来输出警告和错误消息
//clog---ostream类型的对象：关联到标准错误；默认情况下，写到clog的数据是被缓冲的；用来输出程序运行时的一般性消息
//流---字符序列，表示随着时间的推移，字符是顺序生成或消耗的
void printInput(){
    //---使用标准库中的名字
    //标准库定义的所有名字都在命名空间std中
    //---作用域运算符（::）
    std::cout << "Enter two numbers: " << std::endl;
    //---输出运算符（<<）
    //解读：在标准输出上打印消息
    //语法：ostream对象 << 要打印的值
    //此运算符将给定的值写到给定的ostream对象，返回左侧运算对象（ostream）
    //---字符串字面值常量
    //语法："字符序列"
    //---endl操纵符
    //解读：结束当前行，并将与设备关联的缓冲区中的内容刷到设备中
    //缓冲刷新操作可以保证到目前为止程序所产生的所有输入输出都真正写入输出流中，而不是仅停留在内存中等待写入流
    int value1, value2;
    std::cin >> value1 >> value2;
    //---输入运算符（>>）
    //语法：istream对象 >> 存储数据的对象
    //此运算符从给定的istream读入数据，并存入到给定对象。返回左侧运算对象（istream）
    std::cout << "value1 = " << value1 << std::endl;
    std::cout << "value2 = " << value2 << std::endl;
}

//---控制流
//语句一般是顺序执行的：语句块的第1条语句首先执行，然后是第2条语句，依次类推
//1---while语句
//解读：反复执行一段代码，直至给定条件为假为止
//while(condition){
//    statement;
//}
//condition---1个产生真或假的结果的表达式
//while语句持续地交替检测condition（对condition进行求值，即执行表达式）和执行statement，直至condition为假为止
//2---for语句
//解读：包含2部分（循环头和循环体）
//for(init-statement; condition; expression){//循环头
//    //循环体
//}
//参数init-statement：初始化语句，只在for循环入口处执行1次
//参数condition：循环条件，循环体每次执行前都会检查循环条件
//参数expression：表达式，在循环体之后执行
//3---if语句
//if(condition){
//语句
//}

//---类简介
//类定义了自己的数据结构，以及与其关联的一组操作
//类类型（类名）---类定义的类型
//成员函数（方法）---类定义的操作；通常通过调用成员函数来操作特定对象

//---术语表
//参数（argument）---向函数传递的值
//赋值（assignment）---抹去1个对象的当前值，用1个新值取代之
//程序块（block）---{0条或多条语句的序列}
//缓冲区（buffer）---1个存储区域，用于保存数据
//IO设备通常将输入（或输出）数据保存在1个缓冲区中，读写缓冲区的动作与程序中的动作是无关的
//显式刷新输出缓冲，以便强制将缓冲区中的数据写入输出设备
//默认情况下，读cin会刷新cout；程序非正常终止时也会刷新cout
//库类型（library type）---标准库定义的类型，如iostream
//main---操作系统执行一个C++程序时，所调用的函数；每个程序必须有且只有一个命名为main的函数
//命名空间（namespace）---将库定义的名字放在1个单一位置的机智；命名空间可以帮助避免不经意的名字冲突；C++标准库定义的名字在命名空间std中
//变量（variable）---具名对象
//()运算符---调用运算符；跟随在函数名之后，起到调用函数的效果
//.运算符---点运算符；类类型对象.成员
//::运算符---作用域运算费用；访问命名空间中的名字
//#include---头文件包含指令，使头文件中代码可被程序使用



