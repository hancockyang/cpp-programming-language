//
//  main.cpp
//  homework
//
//  Created by hankang yang on 2/3/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class student{
public:
    char name[20], number[20];
    unsigned int nAge;
    int grade[4] = {0,0,0,0}, average;
    
    void averagegrade(int* grade);
    
    student(const char* stname, const char* stnumber, int stnAge, int* stgrade){
        strcpy(name, stname);
        strcpy(number, stnumber);
        nAge = stnAge;
        for (int i = 0; i < 4; i++) {
            grade[i] = stgrade[i];
        }
    }
    
    
};

void student::averagegrade(int* grade){
    int total{0};
    for (int i = 0; i < 4; i++) {
        total = total + grade[i];
    }
    average = total/4;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int stgrade[] = {80,80,90,70};
    student mystudent("Tom","7817",18,stgrade);
    mystudent.averagegrade(stgrade);
    cout<<mystudent.name<<", "<<mystudent.number<<", "<<mystudent.nAge<<", "<<mystudent.average<<endl;
    return 0;
}
