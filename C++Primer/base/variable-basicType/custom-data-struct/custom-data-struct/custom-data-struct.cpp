//自定义数据结构
#include "stdafx.h"
#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data data;
	//使用点操作符访问数据成员
	data.bookNo = "123";
	data.units_sold = 10;
	data.revenue = data.units_sold * 20;
	std::cout << "revenue = " << data.revenue << std::endl;//200

    return 0;
}

