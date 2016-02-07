//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/6/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CDemo{
private:
    int n;
public:
    CDemo(int i = 0):n(i){}              //constructor
    CDemo operator++();                  //prefix
    CDemo operator++(int);               //surfix
    operator int(){return n;}            //force int overloaded
    friend CDemo operator--(CDemo &);    //prefix
    friend CDemo operator--(CDemo&, int);//surfix
};

CDemo CDemo::operator++(){//prefix
    n++;
    return *this;
}

CDemo CDemo::operator++(int k){//surfix
    CDemo tmp(*this); // record the current value
    n++;
    return tmp;
}

CDemo operator--(CDemo &d){//prefix
    d.n--;
    return d;
}

CDemo operator--(CDemo &d, int){//surfix
    CDemo tmp(d);//record the current value
    d.n--;
    return tmp;
}



int main(int argc, const char * argv[]) {
    CDemo d(5);
    cout<<(d++)<<","; //same as d.operator++(0);
    cout<<d<<",";
    cout<<(++d)<<","; //same as d.operator++();
    cout<<d<<endl;
    cout<<(d--)<<","; //same as operator--(d,0);
    cout<<d<<",";
    cout<<(--d)<<";"; //same as operator--d(d);
    cout<<d<<endl;
    return 0;
}
