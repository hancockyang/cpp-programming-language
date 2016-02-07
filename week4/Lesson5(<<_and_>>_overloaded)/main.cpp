//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/6/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex{
    double real, imag;
public:
    Complex(double r=0, double i = 0):real(r), imag(i){};
    friend ostream &operator<<(ostream &os, const Complex &c);
    friend istream &operator>>(istream &is, Complex &c);
};
ostream & operator<<(ostream &os, const Complex & c){
    os<<c.real<<"+"<<c.imag<<"i";
    return os;
}

istream &operator>>(istream &is, Complex &c)
{
    string s;
    is>>s;//write "a+bi" as string to is
    int pos = s.find("+",0);
    string sTmp = s.substr(0, pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos+1, s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return is;
}

int main(){
    Complex c;
    int n;
    cin>>c>>n;
    cout<<c<<","<<n;
    return 0;
}

