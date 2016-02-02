//
//  main.cpp
//  par1
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 5, m = 6;
    const int* p = &n;
    * p = 5;// wrong
    n = 4;  // right
    p = &m; // right
    std::cout << "Hello, World!\n";
    return 0;
}
