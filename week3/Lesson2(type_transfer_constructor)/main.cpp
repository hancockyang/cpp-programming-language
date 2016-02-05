//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/4/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Complex{
public:
    double real, imag;
    Complex(int i){
        cout<<"IntConstructor called"<<endl;
        real = i; imag = 0;
    }
    Complex(double r, double i){
        real = r; imag = r;
    }
};

int main(int argc, const char * argv[]) {
    Complex c1(7,8);     // called the constructor
    Complex c2 = 12;     // pass 12 to intComplex, initialize
    c1 = 9;              // use 9 to call intComplex and pass to c1;
    cout<<c1.real<<","<<c1.imag<<endl;
    return 0;

}
