//
//  main.cpp
//  part1
//
//  Created by hankang yang on 1/31/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//
//  the reference  can be used to change in values in the scope
#include <iostream>
using namespace std;
void swap1(int a, int b)
{
    int temp;
    temp = a; a = b; b = temp;
}
void swap2(int& a, int& b)
{
    int temp;
    temp = a; a = b; b = temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n1 = 1, n2 = 2;
    swap1(n1, n2);
    cout<<n1<<" "<<n2<<endl;
    swap2(n1, n2);
    cout<<n1<<" "<<n2<<endl;
    return 0;
}
