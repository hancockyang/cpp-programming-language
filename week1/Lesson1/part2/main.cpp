//
//  main.cpp
//  l1p1e2
//
//  Created by hankang yang on 1/31/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int MyCompare( const void* elem1, const void* elem2)
{
    unsigned int * p1, * p2;
    p1 = (unsigned int*) elem1;
    p2 = (unsigned int*) elem2;
    return (*p1 % 10) - (*p2 % 10);
    
}

int main(int argc, const char * argv[]) {
    int NUM = 5;
    unsigned int an[] = {8, 123, 11 ,10, 4};
    qsort(an, NUM, sizeof(unsigned int), MyCompare);
    for (int i = 0; i< NUM;i++) {
        printf("%d\n",an[i]);
    }
    
    return 0;
}
