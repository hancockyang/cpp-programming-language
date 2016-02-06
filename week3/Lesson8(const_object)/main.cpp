//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CTest{
private:
    int n;
public:
    CTest() {n = 1;}
    int GetValue() const {return n;}
    int GetValue() {return 2*n;}
};

void PrintObj(const CTest & o)
{
    cout<<o.GetValue()<<endl;
}


int main(){
    const CTest objTest1;
    CTest objTest2;
    PrintObj(objTest1);
    PrintObj(objTest2);
    cout<<objTest1.GetValue()<<", "<<objTest2.GetValue()<<endl;
    return 0;
}

