//
//  main.cpp
//  part
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;


class CTyre{
private:
    int radius;
    int width;

public:
    CTyre(int r, int w): radius(r), width(w){ cout<<"CTyre constructor"<<endl;}
    ~CTyre(){ cout<<"CTyre destructed"<<endl;}
};


class CEngine{
public:
    CEngine(){ cout<<"CEngine constructor"<<endl;}
    ~CEngine(){ cout<<"CEngine destructed"<<endl;}
};


class CCar{
private:
    int price;
    CEngine engine;
    CTyre tyre;
public:
    CCar(int p, int tr, int tw);
    ~CCar(){cout<<"CCar destructor"<<endl;}
};
CCar::CCar(int p, int tr, int w):price(p), tyre(tr,w){cout<<"CCar constructor"<<endl;};

int main(){
    CCar car(200000,17, 225);
    return 0;
}
