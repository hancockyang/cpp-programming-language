//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/3/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Location{
private:
    int x, y;
public:
    void init(int x = 0, int y = 0);
    void valueX(int val) {x = val;}
    int valueX(){return x;}
};


void Location:: init(int X, int Y){
    x = X;
    y = Y;
}

int main(){
    Location A;
    A.init(5);        // use default value of y = 0;
    A.valueX(5);      // void valueX(int val)
    cout<<A.valueX()<<endl; // int valueX()
    
    return 0;
}

