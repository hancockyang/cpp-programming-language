//
//  main.cpp
//  Homework2
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
    
public:
    
    int val;
    
    Base()
    
    { cout << "Base Constructor" << endl; }
    
    ~Base()
    
    { cout << "Base Destructor" << endl;}
    
};

class Base1:virtual public Base { };

class Base2:virtual public Base { };

class Derived:public Base1, public Base2 { };

int main() { Derived d; return 0;}