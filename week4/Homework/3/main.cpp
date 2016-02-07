//
//  main.cpp
//  Homework3
//
//  Created by hankang yang on 2/7/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
class Array2{
private:
    int *ptr = nullptr;
    int i,j;
public:
    Array2(int i_, int j_);              //constructor function
    Array2(){ptr = nullptr;}
    Array2(Array2 &array);                  //copy constructor
    ~Array2();                              //destructor function
    Array2 &operator=(const Array2 &array); //overload =
    int &operator()(int i_, int j_);        //overload()
    int *operator[](int i_);               //overload[]
};
//constructor
Array2::Array2(int i_, int j_){
    i = i_;
    j = j_;
    ptr = new int[i*j];
}
// copy constructor
Array2::Array2(Array2 &array){
    i = array.i;
    j = array.j;
    ptr = new int[i*j];
    memcpy(ptr,array.ptr,sizeof(int)*i*j);
}
// destructor
Array2::~Array2(){
    if (ptr!=nullptr) {
        delete []ptr;
    }
}
// overload =
Array2 &Array2:: operator=(const Array2 &array){
    if (ptr != nullptr) delete [] ptr;
    i = array.i;
    j = array.j;
    ptr = new int[i*j];
    memcpy(ptr, array.ptr, sizeof(int)*i*j);
    return  *this;
    
}
// overload ()
int & Array2::operator()(int i_, int j_){
    return ptr[i_*j+j_];
}
// overload[]
int * Array2::operator[](int i_){
    
    return  ptr+i_*j;
}
int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

