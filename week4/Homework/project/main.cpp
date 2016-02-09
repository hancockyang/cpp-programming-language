//
//  main.cpp
//  project
//
//  Created by hankang yang on 2/8/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAXLEN = 100;

class Bigint{
private:
    int *ptr = nullptr;
    int length = 0;
    string sign = "+";
public:
    //char num[MAXLEN];
    Bigint();                     // constructor
    Bigint(const char * charNum); // overloaded constructor
    Bigint(Bigint &b);            // copy constructor
    ~Bigint();
    void print();
    Bigint & operator=(const Bigint &b);                      // overload '=' operator
    friend Bigint &operator+(const Bigint &a,const Bigint &b);// overload '+' operator
    friend Bigint &operator-(const Bigint &a,const Bigint &b);// overload '-' operator
    friend Bigint &operator*(const Bigint &a,const Bigint &b);// overload '*' operator
    friend Bigint &operator/(const Bigint &a,const Bigint &b);// overload '/' operator
    
};



//constructor
Bigint::Bigint(){
    
}

Bigint::Bigint(const char * charNum){
    length = (int) strlen(charNum);
    ptr = new int[length];
    for (int i = 0; i<length; ++i) {
        ptr[length - 1 - i] = charNum[i] - '0';
    }
}
// copy constructor
Bigint::Bigint(Bigint &b){
    length = b.length;
    ptr = new int[b.length];
    memcpy(ptr, b.ptr, sizeof(int)*b.length);
}


//destructor
Bigint::~Bigint(){
    if (!ptr) { delete [] ptr;}
}

//overload '=' operator

Bigint &Bigint:: operator=(const Bigint &b){
    if (ptr == b.ptr) {return *this;}
    if (b.ptr == nullptr) {
        if (ptr) {
            delete [] ptr;
        }
        ptr = nullptr;
        length = 0;
        return *this;
    }
    if (length<b.length) {
        if (ptr) {
            delete [] ptr;
        }
        ptr = new int[b.length];
    }
    memcpy(ptr, b.ptr, sizeof(int)*b.length);
    length = b.length;
    sign = b.sign;
    return *this;
}

//overload '+' operator
Bigint &operator+(const Bigint &a, const Bigint &b){
    Bigint &result = *new Bigint;
    int maxlen = b.length>a.length?b.length:a.length; // find max len
    int minlen = b.length<a.length?b.length:a.length; // find min len
    
    result.length = maxlen + 1;
    result.ptr = new int[maxlen+1];
    //initialize:
    for (int i = 0; i < result.length; ++i) {result.ptr[i] = 0;}
    // if a and b are the same length then minlen is the same for both
    for (int i = 0; i < minlen; ++i) {
        // carry
        int carry = 0;
        if (a.ptr[i] + b.ptr[i] + result.ptr[i]>=10) {
            result.ptr[i+1]++;
            //carry ++;
            
        }

        result.ptr[i] = (a.ptr[i] + b.ptr[i] + result.ptr[i] )%10;
    }
    // if a and b are different length
    if (b.length==minlen) {
        for (int i = minlen; i < a.length; ++i){
            if (result.ptr[i] + a.ptr[i]>=10) {
                result.ptr[i+1]++;
            }
            result.ptr[i] = (result.ptr[i] + a.ptr[i])%10;
        }
    }
    else if (a.length==minlen){
        for (int i = minlen; i < b.length; ++i){
            if (result.ptr[i] + b.ptr[i]>=10) {
                result.ptr[i+1]++;
            }
            result.ptr[i] = (result.ptr[i] + b.ptr[i])%10;
        }
    }
    return result;
    
}
//overload operator -
Bigint &operator-(const Bigint &a, const Bigint &b){
    Bigint &result = *new Bigint;

    int maxlen = b.length>a.length?b.length:a.length; // find max len
    //int minlen = b.length<a.length?b.length:a.length; // find min len
    
    
    

    
    

    if (a.length>b.length) {
        result = a;
        for (int i = 0; i < b.length; ++i) {
            if (result.ptr[i] - b.ptr[i]<0) {
                result.ptr[i] = result.ptr[i] +10;
                result.ptr[i+1]--;
            }
            result.ptr[i] = result.ptr[i] - b.ptr[i];
        }
    }
    else if (a.length<b.length){
        result = b;
        result.sign = "-";
        for (int i = 0; i < a.length; ++i) {
            if (result.ptr[i] - a.ptr[i]<0) {
                result.ptr[i] = result.ptr[i] +10;
                result.ptr[i+1]--;
            }
            result.ptr[i] = result.ptr[i] - a.ptr[i];
        }
    }
    else {
        for (int i = maxlen-1; i>=0; --i) {
            if (a.ptr[i]>b.ptr[i]) {
                result = a;
                break;
            }
            else {
                result = b;
                result.sign = "-";
                for (int i = 0; i < a.length; ++i) {
                    if (result.ptr[i] - a.ptr[i]<0) {
                        result.ptr[i] = result.ptr[i] +10;
                        result.ptr[i+1]--;
                    }
                    result.ptr[i] = result.ptr[i] - a.ptr[i];
                }
                return result;
            }
            
        }
        for (int i = 0; i < b.length; ++i) {
            if (result.ptr[i] - b.ptr[i]<0) {
                result.ptr[i] = result.ptr[i] +10;
                result.ptr[i+1]--;
            }
            result.ptr[i] = result.ptr[i] - b.ptr[i];
        }
        
        
    }

    return result;
}

//overload '*' operator
Bigint &operator*(const Bigint &a, const Bigint &b){
    Bigint &result = *new Bigint;
    int maxlen = b.length>a.length?b.length:a.length; // find max len
    int minlen = b.length<a.length?b.length:a.length; // find min len
   
    result.length = maxlen + minlen ;
    result.ptr = new int[maxlen + minlen ];
    //initialize:
    for (int i = 0; i < result.length; ++i) {result.ptr[i] = 0;}
    for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j< b.length; ++j) {
            int n = i + j;
            int carry = a.ptr[i]*b.ptr[j]/10;
            if (a.ptr[i]*b.ptr[j]%10 + result.ptr[n]>=10) {
                carry++;
            }
            result.ptr[n] = (a.ptr[i]*b.ptr[j]%10 + result.ptr[n])%10;
            if (carry> 0){result.ptr[n+1] = result.ptr[n+1] + carry;}
            
        }
    }
    
    return result;
    
}

// overload '/' operator
Bigint &operator/(const Bigint &a, const Bigint &b){
    Bigint &result = *new Bigint;
    if (a.length<b.length) {
        result.length = 1;
        result.ptr = new int[1];
        result.ptr[0] = 0;
    }
//    else if (a.length==b.length){
//        for (int i = a.length-1; i>=0; --i) {
//            if (a.ptr[i]<b.ptr[i]) {
//                result.length = 1;
//                result.ptr = new int[1];
//                result.ptr[0] = 0;
//                break;
//            }
//        }
//        
//    }
    else{
        result = a;
        int n = 0;
        do  {
            result = result - b;
            n++;
        }while (result.sign == "+" ) ;
        //result = result-b;
        //result = result-b;
        //cout<<n<<endl;
        //cout<<result.sign;
  
        
        
        
    }
    return result;
}

//print void
void Bigint::print(){
    //int count = 0;
    if (sign == "-"){cout<<sign;}
    for (int i = 0; i<length; i++) {
        cout<<ptr[length - 1 - i];
    }
    cout<<endl;
    //cout<<"length: "<< length<<endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    char a[MAXLEN], b[MAXLEN];
    cin>>a;
    cin>>b;
    Bigint a1(a), b1(b), c1, c2, c3, c4;
    //a1.print();
    //b1.print();
    c1=a1 + b1;
    c2=a1 - b1;
    c3=a1 * b1;
    //c4=a1 / b1;
    //cin>>b;
    //cout<<a<<", "<<strlen(a)<<endl;
    
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    return 0;
}
