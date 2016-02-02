//
//  main.cpp
//  part4
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    const int & r = n;
    r = 5;// wrong
    n = 5;//ok
    std::cout << "Hello, World!\n";
    return 0;
}
