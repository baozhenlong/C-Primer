//
//  main.cpp
//  const
//
//  Created by mac on 2018/7/5.
//  Copyright © 2018年 mac. All rights reserved.
//

//const限定符
//const对象一旦创建后其值就不能再改变，所以const对象必须初始化，初始值可以是任意复杂的表达式
//任何试图对const对象赋值的行为都将引发错误
#include <iostream>
int get_size();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //---const
    //常量特性仅仅在执行改变其值的操作时，才会发挥作用
    //编译器将在编译过程中把用到常量的地方都替换成对应的值
    
    //---默认状态下，const对象仅在文件内有效
    //当多个文件中出现了同名的const变量时，其实等同于在不同文件中分别定义了独立的变量
    //---特殊情况：在一个文件中定义const，而在其他多个文件中声明并使用它
    //file.h头文件---extern const int bufSize;//指明bufSize并非本文件所独有；与file.h中定义的bufSize是同一个
    //file.cpp---extern const int bufSize = 512;//定义并初始化了一个常量，该常量能被其他文件访问
    
    //---const的引用
    //可以把引用绑定到const对象上（对常量的引用）
    //与普通引用不同的是，对常量的引用不能被用作修改它所绑定的对象
    const int ci = 22;
    const int &rci = ci;//正确，引用及其对应的对象都是常量
    //rci = 2;//错误，rci是对常量的引用
    //int &rci2 = ci;//错误，试图让一个非常量的引用指向一个常量对象
    //---初始化和对const的引用
    //初始化---将初始值转换成引用类型的值
    //引用的类型必须与其所引用对象的类型一致的例外情况
    //例外1---在初始化常量引用时，允许使用任意表达式作为初始值，只要该表达式的结果能转换成引用的类型即可；尤其，允许为常量引用绑定非常量的对象、字面值，甚至是个一般表达式
    int i = 22;
    const int &r1 = i;//允许将const int&绑定到一个普通int对象上
    const int &r2 = 22;//正确：r2是一个常量引用
    const int &r3 = r1 * 2;//正确：r3是一个常量引用
    //int &r4 = r1 * 2;//错误：r4是一个普通的非常量引用
    double dval = 3.14;
    const int &ri = dval;
    std::cout << "ri = " << ri << std::endl;//3
    //编译器将上述代码变成了如下形式
    const int temp = dval;//由双精度浮点数生成一个临时的整型常常量
    std::cout << "temp = " << temp << std::endl;//3
    const int &rtemp = temp;//让rtemp绑定这个临时量
    std::cout << "rtemp = " << rtemp << std::endl;//3
    //临时量对象（简称临时量）：当编译器需要一个空间来暂存表达式的求值结果时，临时创建的一个未命名的对象
    //---对const的引用可能引用一个并非const的对象
    //常量引用仅对引用可参与的操作做出了限定，对于引用对象本身是不是一个常量未作限定
    //如果引用的对象是个非常量，则可以通过其他途径修改它的值
    
    //---指针和const
    //1---指向常量的指针
    //与引用一样，也可以令指针指向常量或非常量
    //指向常量的指针不能用于改变其所指对象的值
    //要想存放常量对象的地址，只能使用指向常量的指针
    const double pi = 3.14;
    //double *ptr = &pi;错误：ptr是一个普通指针
    const double *cptr = &pi;//正确：cptr可以指向一个双精度常量
    //*cptr = 1;错误：不能给*cptr赋值
    //指针的类型必须与其所指对象的类型一致的例外情况
    //例外1---允许令一个指向常量的指针指向一个非常量对象
    double dd = 3.14;
    cptr = &dd;//正确：但不能通过cptr改变dd的值
    //和常量引用一样，指向常量的指针没有规定其所指的对象必须是一个常量；所谓指向常量的指针的仅仅要求不能通过该指针改变对象的值，而没有规定那个对象的值不能通过其他途径改变
    //2---const指针（常量指针）
    //指针是对象而引用不是，因此允许把指针本身定为常量
    //常量指针必须初始化，而且一旦初始化完成，则它的值（存放在指针的那个地址）就不能再改变了
    //*const---说明指针是一个常量；不变的是指针本身的值，而非指向的那个值
    int num = 0;
    int *const pNum = &num;//pNum将一直指向num；首先是个常量，再是个指针，再是指向一个int对象
    const double dnum = 3.14;
    const double *const cpnum = &dnum;//cpnum是一个指向常量对象的常量指针
    //不能修改指针值
    //---顶层const
    //指针本身是一个对象，它又可以指向另外一个对象
    //指针本身是不是常量以及指针所指的是不是一个常量就是两个相互独立的问题
    //顶层const---表示指针本身是个常量；更一般的，表示任意的对象是常量
    //底层const---表示指针所指的对象是一个常量
    int value = 0;
    int *const p1 = &value;//不能改变p1的值，这是一个顶层const
    const int cvalue = 2;//不能改变cvalue的值，这是一个顶层const
    const int *p2 = &cvalue;//不能改变p2的值，这是一个底层const
    const int *const p3 = p2;//靠右的const是顶层const；靠左的是底层const
    const int &r = cvalue;//用于声明引用的const都是底层const
    //当执行对象的拷贝操作时
    //顶层const不受影响
    //底层const有限制：拷入和拷出的对象必须具有相同的底层const资格，或者两个对象的数据类型必须能够转换（一般来说，非常量可以转换成常量，反之则不行）
    
    //---constexpr和常量表达式
    //常量表达式：指值不会改变并且在编译过程就能得到计算结果的表达式
    //字面值属于常量表达式
    //用常量表达式初始化的const对象也是常量表达式
    //一个对象（或表达式）是不是表达式由它的数据类型和初始值共同决定
    const int max_files = 20;//是
    const int limit = max_files + 1;//是
    int staff_size = 27;//不是；数据类型只是一个普通int而非const int
    const int sz = get_size();//不是；具体值在运行时才能获取到
    //---constexpr变量
    //C++11新标准规定，允许将变量声明为constexpr类型，以便由编译器来验证变量的值是否是一个常量表达式
    //声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化
    //---字面值类型
    //算术类型
    //引用
    //指针---初始值必须是nullptr或0或存储于某个固定地址中的对象
    
    
    return 0;
}

int get_size(){
    return 10;
}
