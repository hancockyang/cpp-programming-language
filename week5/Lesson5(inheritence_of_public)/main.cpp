//
//  main.cpp
//  part5
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class Base{
public:
    int n;
    Base(int i):n(i){
        cout<<"Base "<<n<<" constructed"<<endl;
    }
    ~Base(){
        cout<<"Base "<<n<<" destructed"<<endl;
    }
};
class Derived: public Base{
public:
    Derived(int i):Base(i){
        cout<<"Derived "<<n<<" constructed"<<endl;
    }
    ~Derived(){
        cout<<"Derived "<<n<<" destructed"<<endl;
    }

    
};
class MoreDerived: public Derived{
public:
    MoreDerived():Derived(4){
        cout<<"Derived "<<n<<" constructed"<<endl;
    }
    ~MoreDerived(){
        cout<<"Derived "<<n<<" destructed"<<endl;
    }
    
    
};


int main(int argc, const char * argv[]) {
    MoreDerived Obj;
    return 0;
}
