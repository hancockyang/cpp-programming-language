//
//  main.cpp
//  Homework2
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class A {
public:
    int val;
    A(int n = 0){val = n;}
    int & GetObj(){return val;}//it returns the reference to val
};
int main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}