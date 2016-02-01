//
//  main.cpp
//  separate compilation
//
//  Created by hankang yang on 1/30/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include "Vector.h"
#include <cmath>
using namespace std;

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); ++i) {
        sum+= sqrt(v[i]);
        
    }
    return sum;
}

void f(Vector& v)
{
    try{
        v[v.size()] = 7;
    }
    catch(out_of_range){
        cout<<"out of range\n";
    
    }
}



int main() {
    Vector v(5);
    for (int i=0; i!=v.size(); ++i) {
        v[i] =  i;
    }
    double s = sqrt_sum(v);
    cout<<v.size()<<"\n";
    cout<<"s = "<<s<<"\n";
    f(v);
//   test();
    return 0;
}
