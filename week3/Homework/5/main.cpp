//
//  main.cpp
//  Homework5
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class CSample {
    
    int x;
    
public:
    
    CSample() { cout << "C1" << endl; }
    
    CSample(int n ) {
        
        x = n;
        
        cout << "C2,x=" << n << endl; }
    
};

int main(){
    
    CSample array1[2];
    
    CSample array2[2] = {6,8};
    
    CSample array3[2] = {12};
    
    CSample * array4 = new CSample[3];
    
    return 0;
    
}
