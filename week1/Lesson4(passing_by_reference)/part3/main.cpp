//
//  main.cpp
//  part3
//
//  Created by hankang yang on 1/31/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//
//  const reference
#include <iostream>

int main(int argc, const char * argv[]) {
    int n = 100;
    const int & r = n;
    r = 200; //wrong
    n = 300; //right
    return 0;
}
