//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/3/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
//---------------------------------------------
class Complex{
private:
    double real, imag;
public:
    void Set(double r, double i);
    Complex(double r, double i);
    Complex(double r);
    Complex(Complex c1, Complex c2);
    void Cprint(Complex &c){
        cout<<c.real<<" "<<c.imag<<endl;
    }
};

Complex::Complex(double r, double i){
    real = r; imag = i;
}
Complex::Complex(double r){
    real = r; imag = 0;
}
Complex::Complex(Complex c1, Complex c2){
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}
//---------------------------------------------
class CSample{
    int x;
public:
    CSample(){
        cout<<"Constructor 1 Called"<<endl;
    }
    CSample(int n){
        x = n;
        cout<<"Constructor 2 Called"<<endl;
    }
};
//--------------------------------------------
int main(){
    Complex c1(3), c2(1,0), c3(c1,c2);
    c1.Cprint(c1);
    c1.Cprint(c2);
    c3.Cprint(c3);
    CSample array1[2];
    cout<<"step1"<<endl;
    CSample array2[2] = {4,5};
    cout<<"step2"<<endl;
    CSample array3[2] = {3};
    cout<<"step3"<<endl;
    CSample* array4 = new CSample[2];
    delete[]array4;
    return 0;
}

