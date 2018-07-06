//
//  main.cpp
//  custom-data-struct
//
//  Created by mac on 2018/7/5.
//  Copyright © 2018年 mac. All rights reserved.
//

//自定义数据结构
#include <iostream>
#include "Sales_data.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Sales_data data;
    //使用点操作符访问数据成员
    data.bookNo = "123";
    data.units_sold = 10;
    data.revenue = data.units_sold * 20;
    std::cout << "revenue = " << data.revenue << std::endl;//200
    
    return 0;
}
