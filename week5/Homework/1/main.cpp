//
//  main.cpp
//  Homework1
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

using namespace std;

class B {
    
public:
    
    B(){ cout << "B_Con" << endl; }
    
    ~B() { cout << "B_Des" << endl; }
    
};

class C:public B {
    
public:
    
    C(){ cout << "C_Con" << endl; }
    
    ~C() { cout << "C_Des" << endl; }
    
};

int main() {
    
    C * pc = new C;
    
    delete pc;
    
    return 0;
    
}