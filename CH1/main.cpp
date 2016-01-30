//
//  main.cpp
//  helloword
//
//  Created by hankang yang on 1/29/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
double square(double x)
{
    return x*x;
}

void print_square(double x)
{
    cout<<"the square of"<<x<<" is "<<square(x)<<"\n";
}

void some_function(){
    double d =2.2;
    int i =7;
    d = d + i;
    i = d*i;
}

int main() {
    // insert code here...
    cout << "Hello, World!\n";
    print_square(1.234);
    return 0;
}

