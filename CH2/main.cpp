//
//  main.cpp
//  helloword
//
//  Created by hankang yang on 1/29/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <complex> //include complex value
#include <vector>
#include <cmath>
using namespace std;

constexpr double square(double x) {return x*x;}

void print_square(double x){ cout<<"the square of"<<x<<" is "<<square(x)<<"\n";}

// 2.2.4 Tests and Loops------------------------------------------------
bool accept3(){
    int tries = 1;
    while (tries < 4) {
        cout<<"Do you want to proceed (y or n)?\n";  // write quesion
        char answer = 0;
        cin>>answer;                                 // read answer
        
        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout<<"Sorry, I don't understand that.\n";
                ++tries;//increment
        }
    }
    cout<<"I'll take that for a no.\n";
    return false;
}

void some_function(){
//2.2.2 Types, Variables and Arithmetic-----------------------------
    double d =2.2;                            //define double
    double d1{2.2};                           //define double
    vector<int> v{1,2,3,4,5};                 //define vector
    int i =7;                                 //define integer
    d = d + i;
    i = d1*i;
    complex<double> z={1,2};                  //define complex number
// 2.2.3 constant--------------------------------------------------
    const int dmv = 17;
    int var = 17;
    constexpr double max1 = 1.4*square(dmv); // Ok if square(17) is constant expression
                                             // constexpr double max2 = 1.4*square(var); error
    const double max3 = 1.4*square(var);     // Ok, may be evaluated at run time
    cout<<"complex number v = "<<z<<"\n";
    cout<<"v[1] = "<<v[1]<<"\n";
    cout<<"max1 = "<<max1<<"\n";
    cout<<"max3 = "<<max3<<"\n";
    
}
//2.2.5 Pointers, Arrays, and Loops---------------------------------
void copy_fct(){
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];
    
    for (auto i=1; i!=10; ++i) { // from i = 1 until i!=1, increment by 1
        v2[i] = v1[i];
    }
    for (auto& x:v1) { ++x; } // suffix & means reference to
    
}

void print(){
    int v[] ={0,1,2,3,4,5,6,7,8,9};
    
    for (auto x:v) cout<<x<<"\n";    // for every element of v, from the first to the last, place a copy in x and print it
    
    for (auto x:{10,21,32,43,54,65})cout<<x<<"\n";//
    
}
int count_x(char* p, char x)
    //count the number of occurrences of x in p[]
    //p is assumed to point to a zero-terminated array of char (or to nothing)
    {
        if (p==nullptr) return 0;
        int count = 0;
        for (; *p!=x;++p){
            if (*p == x) {
                ++count;
            }
            
        }
        return count;
    
}
//2.3.1 Structures-------------------------------------------------
//struct Vector{
//    int sz;
//    double* elem;
//};
//void vector_init(Vector& v, int s){
//    v.elem = new double[s]; // allocate an array of s doubles
//    v.sz   = s;
//}
//double read_and_sum(int s)
//    // read s integers from cin and return their sum; s is assumbed to be positive
//{
//    Vector v;
//    vector_init(v,s);
//    for (int i=0; i!=s; ++i) {
//        cin>>v.elem[i];
//    }
//    double sum = 0;
//    for (int i=0; i!=s; ++i) {
//        sum+=v.elem[i];
//    }
//    return sum;
//}
// 2.3.2 Class----------------------------------------------------------------
class Vector{
public:
    Vector(int s) :elem{new double[s]}, sz{s} {}//initialized the Vector class with elem and sz
    double& operator[](int i){return elem[i];}  //element acess: subscripting, defines operator [i]
    int size(){return sz;}                      //size function
private:
    double* elem;
    int sz;
};
double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumbed to be positive
{
    Vector v(s);
    
    for (int i=0; i!=v.size(); ++i) {
        cin>>v[i];
    }
    double sum = 0;
    for (int i=0; i!=v.size(); ++i) {
        sum+=v[i];
    }
    return sum;
}
//main function-----------------------------------------------------
int main() {
    //print_square(1.234);
    //some_function();
    //accept3();
//2.2.5 Pointers, Arrays, and Loops-----------------------------------
    vector<int> v{1,2,3,4,5};
    int* p = &v[3];          // p is a pointer that points to the address of v[3], prefix & is the address of
    int x = *p;              // *p is the object that p points to, x is the value that stored in the pointed address
    cout<<"p = "<<p<<"\n";
    cout<<"x = "<<x<<"\n";
    print();
    //double* pd = nullptr;// the null pointer
//2.3.1 Structures and 2.3.2 Class-------------------------------------------------
    int s = read_and_sum(9);
    cout<<"s = "<<s<<"\n";
    
    return 0;
}

