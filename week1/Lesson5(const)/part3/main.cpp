//
//  main.cpp
//  par3
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
void MyPrintf(const char* p)
{
    strcpy(p,"this"); //wrong strcpy(char* )
    printf("%s",p);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
