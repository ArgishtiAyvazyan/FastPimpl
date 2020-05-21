/**
 * @file        Interface.h
 * @author      Argishty Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       The example of using FastPimple.
 * @date        10-05-2020
 * @copyright   Copyright (c) 2020
 */

#include <iostream>
#include <limits>
#include "Interface.h"


int main()
{
    Interface obj;

    obj.doWork();

    Interface obj2 { std::numeric_limits<int>::max() };

    obj2.doWork();

    std::cout << "End..." << std::endl;
    return 0;
}