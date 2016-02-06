//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/6/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;

class String{
private:
    char* str;
public:
    String(){str = nullptr;}
    const char* c_str(){return str;}
    char* operator=(const char* s);
    String &operator=(const String &s);
    ~String();
};
// overload the operator
char* String::operator=(const char* s){
    
    if (str) delete [] str;         // makesure the char* str is not pointing the nullptr
    if (s) {
        str = new char[strlen(s)+1]; // +1 is for
        strcpy(str,s);
    }
    else
        str = nullptr;
    return str;
}
String &String:: operator=(const String &s){
    if (str == s.str) {return *this;}
    if (str) delete [] str;
    str = new char[strlen(s.str)+1];
    strcpy(str,s.str);
    return *this;
}

//Destructor
String::~String(){
    if (str) {
        delete [] str;
    }
}
//Main function
int main(int argc, const char * argv[]) {
    String s, s1, s2;
    s = "Good Luck,";
    cout<<s.c_str()<<endl;
    //String s2 = "hell!" wrong, because it is decleration not operator
    s = "Shenzhou 8!";
    s1 = "This";
    s2 = "That";
    s1 = s2;
    cout<<s.c_str()<<endl;
    cout<<s1.c_str()<<endl;
    
    return 0;
}
