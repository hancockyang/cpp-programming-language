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
public:
    Complex(double r = 0.0, double i = 0.0){
        real = r;
        imaginary = i;
    }
    Complex operator+ (const Complex &);
    Complex operator- (const Complex &);
    double real;
    double imaginary;
};

Complex operator+(const Complex &a, const Complex &b){
    return Complex(a.real+b.real, a.imaginary+b.imaginary);
}

Complex Complex::operator+(const Complex &operand2){
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2){
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Complex a(1,2), b(2,3), c;
    c = a + b;
    cout<<c.real<<", "<<c.imaginary<<endl;
    return 0;
}
