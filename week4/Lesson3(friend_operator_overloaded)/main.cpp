//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/6/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class Complex{
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i){};
    Complex operator+(double r);
    friend Complex operator+(double r, const Complex &c);
    
};

Complex Complex::operator+(double r){ //c+5
    return Complex(real+r, imag);
}
Complex operator+(double r, const Complex &c){
    return Complex(c.real+r, c.imag);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
