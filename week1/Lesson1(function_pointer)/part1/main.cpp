//
//  main.cpp
//  l1p1
//
//  Created by hankang yang on 1/31/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

void PrintMin(int a, int b){
    if (a<b)
        printf("%d\n",a);
        
    else
        printf("%d\n",b);
    
}

int main(int argc, const char * argv[]) {
    
    void(* pf)(int,int);
    int x{4},y{5};
    pf = PrintMin;
    pf(x,y);
    return 0;
}
