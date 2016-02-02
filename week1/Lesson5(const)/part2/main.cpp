//
//  main.cpp
//  part2
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    const int* p1; int* p2;
    p1 = p2;       // right
    p2 = p1;       // wrong
    p2 = (int* )p1;// forced to change
    std::cout << "Hello, World!\n";
    return 0;
}
