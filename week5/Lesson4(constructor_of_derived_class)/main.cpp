//
//  main.cpp
//  part4
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Skill{
public:
    Skill(int n){}
};
// base class
class Bug{
private:
    int nLegs; int nColor;
public:
    int nType;
    Bug(int legs, int color); // base constructor
    void PrintBug(){};
};

Bug::Bug(int legs, int color):nLegs(legs),nColor(color){}
// derived class
class FlyBug: public Bug{
    int nWings;
    Skill sk1,sk2;
public:
    FlyBug(int legs, int color, int wings); //derived constructor
};
// wrong way
//FlyBug::FlyBug(int legs, int color, int wings){
//    nLegs = legs;    // base private
//    nColor = color;  // base private
//    nType = 1;       // wrong
//    nWings = wings;
//}

//right way
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs,color),sk1(5),sk2(color){
    nWings = wings;
}

class Base{
public:
    int n;
    Base(int i):n(i){
        cout<<"Base "<<n<<" constructed"<<endl;
    }
    ~Base(){cout<<"Base "<<n<<" destructed"<<endl;}
};

class Derived:public Base{
public:
    Derived(int i):Base(i){
        cout<<"Derived constructed"<<endl;
    }
    ~Derived(){
        cout<<"Derived destructted"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    FlyBug fb(2,3,4);
    fb.PrintBug();
    fb.nType = 1;
    //fb.nLegs = 2; //error, private
    Derived Obj(3);
    
    return 0;
}
