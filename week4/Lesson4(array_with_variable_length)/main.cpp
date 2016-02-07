//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/6/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CArray{
    int size;                             // number of element
    int *ptr;                             // points to the dynamic allocatable array
public:
    CArray(int s = 0);                    // constructor s is the number of element
    CArray(CArray &a);                    // copy constructor
    ~CArray();                            // destructor
    void push_back(int v);                // add element to the end of array
    CArray &operator = (const CArray & a);// overload the =, deep copy
    int length(){return size;}            // return the number of element
    int &operator[] (int i);              // overload [] operator
};
//cosntructor
CArray::CArray(int s):size(s){
    if (s==0) {
        ptr = nullptr;
    }
    else
        ptr = new int[s];
}
//copy constructor: deep copy
CArray::CArray(CArray &a){
    if(!a.ptr){
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr, sizeof(int)*a.size);//copy a.ptr to ptr of sizeof(int)*a.size
    size = a.size;
}
// destructor:
CArray::~CArray()
{
    if(ptr) delete[] ptr;
}
// overload = operator (deep copy):
CArray& CArray::operator=(const CArray &a){
    if (ptr == a.ptr) { //make sure that a = a is right
        return *this;
    }
    if (a.ptr==nullptr) {// if a is empty
        if (ptr) {
            delete [] ptr;
        }
        ptr = nullptr;
        size = 0;
        return *this;
    }
    if (size<a.size) {// if alreay have enough size, then don't need to open new
        if (ptr) {
            delete [] ptr;
        }
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
    return *this;
}
// overload [] operator
int &CArray::operator[] (int i){     // int& type can be changed not int
    return ptr[i]; //it can support n = a[i] and a[i] = 4l
}

// push_back
void CArray::push_back(int v)
{
    if(ptr){
        int *tmpPtr = new int[size+1]; // reallocate the space
        memcpy(tmpPtr, ptr, sizeof(int)*size);// copy the original to the temp
        delete [] ptr;//realse the original
        ptr = tmpPtr;//copy the temp to original
    }
    else // if empty
        ptr = new int[1];
    ptr[size++] = v;//add element
}

    
int main(int argc, const char * argv[]) {
    CArray a;
    for (int i = 0; i<5; ++i) {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i<a.length(); ++i) {
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    a2 = a3;
    for (int i = 0; i<a2.length(); ++i) {
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i<a4.length(); ++i) {
        cout<<a4[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
