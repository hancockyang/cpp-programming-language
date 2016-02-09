//
//  main.cpp
//  part2
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class base{
    int j;
public:
    int i;
    void func();
};

class derived:public base{
public:
    int i;
    void access();
    void func();
};


void derived:: access()
{
    //j = 5;     // wrong, base private
    i = 5;       // derived i
    base:: i = 5;// base i
    func();      // derived func()
    base::func();// base func()
}


class Father{
private:
    int nPrivate;
public:
    int nPublic;
protected:
    int nProtected;
};

class Son:public Father{
    void AccessFather(){
        nPublic = 1;
        //nPrivate = 1; wrong, it is base private
        nProtected = 1; // derived from base class
        //Son f;
        //f.nProtected = 1; //wrong the object f does not have member called nProtected
    }

};


int main(int argc, const char * argv[]) {
    derived obj;
    obj.i = 1;      // derived
    obj.base::i = 1;// base
    std::cout << "Hello, World!\n";

    Father f;
    Son s;
    f.nPublic = 1;
    s.nPublic = 1;
    //f.nProtected = 1;
    //f.nPrivate = 1;
    //s.nProtected = 1;
    //s.Privated = 1;
    
    
}
