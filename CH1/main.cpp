//
//  main.cpp
//  helloword
//
//  Created by hankang yang on 1/29/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <complex> //include complex value
#include <vector>
#include <cmath>
using namespace std;

constexpr double square(double x) {return x*x;}

void print_square(double x)
{
    cout<<"the square of"<<x<<" is "<<square(x)<<"\n";
}

void some_function(){
    double d =2.2;                            //define double
    double d1{2.2};                           //define double
    vector<int> v{1,2,3,4,5};                 //define vector
    int i =7;                                 //define integer
    d = d + i;
    i = d1*i;
    complex<double> z={1,2};                  //define complex number
    const int dmv = 17;
    int var = 17;
    constexpr double max1 = 1.4*square(dmv); // Ok if square(17) is constant expression
                                             // constexpr double max2 = 1.4*square(var); error
    const double max3 = 1.4*square(var);     // Ok, may be evaluated at run time
    cout<<"complex number v = "<<z<<"\n";
    cout<<"v[1] = "<<v[1]<<"\n";
    cout<<"max1 = "<<max1<<"\n";
    cout<<"max3 = "<<max3<<"\n";
    
}

int main() {
    // insert code here...
    cout << "Hello, World!\n";
    print_square(1.234);
    some_function();
    return 0;
}

