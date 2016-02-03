//
//  main.cpp
//  part
//
//  Created by hankang yang on 2/2/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class CEmployee{
private:
    char szName[30];
public:
    int salary;
    void setName(const char* name);
    void getName(char* name);
    void averageSalary(CEmployee e1, CEmployee e2);
};

void CEmployee::setName(const char* name){
    strcpy(szName, name);//ok
}
void CEmployee::getName(char* name){
    strcpy(name,szName);//ok
}
void CEmployee::averageSalary(CEmployee e1, CEmployee e2){
    salary = (e1.salary + e2.salary)/2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    CEmployee e;
    //strcpy(e.szName, "Tom123456789"); //wrong, szName is local
    e.setName("Tom");
    char* name;
    e.getName(name);
    cout<<name<<endl;
    e.salary = 5000;
    return 0;
}
