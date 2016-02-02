//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
inline int Max1(int a, int b)
 {
     if(a>b) return a;
     return b;
     }
int Max(int a, int b)
{
    if(a>b) return a;
    return b;
}
int Max(int n1, int n2, int n3)
{
    if(n1>n2 && n1>n3) return n1;
    if(n2>n1 && n2>n3) return n2;
    
    return n3;
}
int Max(double a, double b)
{
    if(a>b) return a;
    return b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a;
    std::cout << "Hello, World!\n";
    return 0;
}
