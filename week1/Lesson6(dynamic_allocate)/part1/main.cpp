//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int* pn;
    pn = new int;
    * pn = 5;
    delete pn;
    
    int* p;
    int i = 5;
    p = new int (i*10);
    delete [] p;
    std::cout << "Hello, World!\n";
    return 0;
}
