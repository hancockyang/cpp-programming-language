//
//  main.cpp
//  par2
//
//  Created by hankang yang on 1/31/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//
//  reference can be used to be the function's return value
#include <iostream>
using namespace std;
int n = 4;
int & SetValue(){return n;}
int main(int argc, const char * argv[]) {
    // insert code here...
    SetValue() = 40;
    cout<<n<<endl;
    return 0;
}
