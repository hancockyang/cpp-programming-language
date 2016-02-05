//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Complex{
public:
    double real, imag;
    void Print(){cout<<real<<", "<<imag<<endl;}
    Complex(double r, double i): real(r),imag(i)
    {   }
    Complex AddOne(){
        this -> real++; //same as real++
        this -> Print();//same as Print
        return *this;
    }
};
class A
{
    int i;
public:
    void Hello(){cout<<"Hello"<<endl;}
};


int main(){
    Complex c1(1,1), c2(0,0);
    c2 = c1.AddOne();
    A* p = NULL;
    p -> Hello();

    return 0;
}
