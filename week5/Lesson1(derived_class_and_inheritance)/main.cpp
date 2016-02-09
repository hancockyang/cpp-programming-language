//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/9/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class CStudent{
private:
    string name;
    string id;
    char gender;
    int age;
public:
    void PrintInfo(){
        cout<<name<<" "<<id<<" "<<gender<<" "<<age<<" ";
    }
    
    void SetInfo(const string &name_, const string &id_, int age_, char gender_){
        name = name_;
        id = id_;
        age = age_;
        gender = gender_;
    }
    
    string GetName(){return name;}
    
};

class CUndergraduateStudent:public CStudent{
private:
    string department;
public:
    void QualifiedForBaoyan(){
        CStudent::PrintInfo();//call the base class function, overwrite it
        cout<<"Department: "<<department<<endl;
    }
    void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_){
        CStudent::SetInfo(name_, id_, age_, gender_); // call the base class
        department = department_;
    }
};


int main(int argc, const char * argv[]) {
    CUndergraduateStudent s2;
    s2.SetInfo("Harry Potter", "118829212", 19, 'M', "Computer Science");
    cout<<s2.GetName()<<" "<<endl;
    s2.QualifiedForBaoyan();
    s2.PrintInfo();
    return 0;
}
