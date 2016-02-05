//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/4/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
//class A
//{
//public:
//    A(){};
//    A(A & a){
//        cout<<"Copy constructor called"<<endl;
//    }
//};
//void Func(A a1){}

class A{
public:
    int v;
    A(int n){v = n;cout<<"Copy constructor called"<<endl;};
    A(const A &a){
        v = a.v;
        //cout<<"Copy constructor called"<<endl;
    }
};
A Func(){
    A b(4);
    return b;
}

int main(int argc, const char * argv[]) {
//    A a2;
//    Func(a2);
    cout<<Func().v<<endl;
    return 0;
}
