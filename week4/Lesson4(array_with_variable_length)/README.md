# Array with varying length
Image the follow program:
```
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    CArray a; // a is empty
    for (int i = 0; i<5; ++i) {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int = i = 0; i<a.length(); ++i) {
        cout<<a2[i]<<" ";
    }
    a2 = a3;// a2 is empty
    for (int i = 0; i<a2.length(); ++i) {
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i<a4.length(); ++i) {
        cout<<a4[i]<<" ";
    }
    
    
    return 0;
}
```
The output is:

0 1 2 3 4

0 1 2 100 4

In order to writh the `CArray` class we need:
- constructor, destructor, memeber functions
- we need dynamic allocatable memory to store the elements, using pointer, can be release in destructor
- `=` needs overload
- `[]` need overload, a2 is not a array name, it is class name
- a4(a) uses copy constructor, cant use default.
## Declare class
```
class CArray{
    int size;                             // number of element
    int *ptr;                             // points to the dynamic allocatable array
public:
    CArray(int s = 0);                    // s is the number of element
    CArray(CArray &a);                    // copy constructor
    ~CArray();                            // destructor
    void push_back(int v);                // add element to the end of array
    CArray &operator = (const CArray & a);// overload the =, deep copy
    int length(){return size;}            // return the number of element
    int &operator[] (int i)               // overload [] operator
};

```
## Constructor
```
CArray::CArray(int s):size(s){
    if (s==0) {                 // if size is zero then nullptr
        ptr = nullptr;
    }
    else                        // else open a dynamic memory
        ptr = new int[s];
}
```
## Copy constructor: deep copy
```
CArray::CArray(CArray &a){
    if(!a.ptr){             // if a is nullptr the copied is also null
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr, sizeof(int)*a.size);//copy a.ptr to ptr of sizeof(int)*a.size
    size = a.size;
}
```
## Destructor
```
CArray::~CArray()
{
    if(ptr) delete[] ptr; //if ptr is not nullptr, realse it
}
```
## Overload = operator (deep copy)
```
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
```
## Overload [] operator
```
int &CArray::operator[] (int i){     // int& type can be changed not int
    return ptr[i]; //it can support n = a[i] and a[i] = 4l
}
```
## push_back function
```
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
```
## Main function
```
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
```

