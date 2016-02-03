# Class
## Example (Rectangular)
```
#include <iostream>
using namespace std;
class CRectangle{
    public:
    int w, h;
    
    void Init(int w_,int h_){
        w = w_; h = h_;
    }
    int Area(){
        return w*h;
    }
    int Perimeter(){
        return 2*(w+h);
    }
};
int main(int argc, const char * argv[]) {
    int w,h;
    CRectangle r, r1, r2;
    cin>>w>>h;
    r.Init(w, h);
    cout<<r.Area()<<endl<<r.Perimeter()<<endl;
    r1.w = 5;
    r2.Init(3,4);
    return 0;
}
```
The class of `CRectangle` has the 
* Member variables:
```
int w;
int h;
```
* Member functions:
```
int Area();
int Perimeter();
void Init(int w_, int h_);
```
Together, they are Class members
## In the main function
```
int main(int argc, const char * argv[]) {
    int w,h;
    CRectangle r, r1, r2;
    cin>>w>>h;
    r.Init(w, h);
    cout<<r.Area()<<endl<<r.Perimeter()<<endl;
    r1.w = 5;
    r2.Init(3,4);
    return 0;
}
```
we define `r`, `r1`, and `r2` as class of `CRectangle`.
we can also pass the value by calling `r.Init(w,h)`, `r.Area()`, and `r.Perimeter`. They argument can also be pass by
using `r1.w=5`. Moreover, the `r1` and `r2` are independent class. we can use `r1 = r2;`
## How to access the member in the class
* object.member
```
CRetangle r1, r2;
r1.w = 5;
r2.Init(3,4);
```
* pointer -> member
```
CRectangle r1, r2;
CRectangle* p1 = &r1;
CRectangle* p2 = &r2;
p1 -> w = 5;
p2 -> Init(3,4);
```
* &P.member (they are the same)
```
CRectangle r2;
CRectangle &rr = r2;
rr.w = 5;
rr.Init(3,4);
```
## Print out (pass the class to the function using reference)
```
void PrintRectangle(CRectangle &r){
        cout<<r.Area()<<","<<r.Perimeter();
}
CRectangle r3;
r3.Init(3,4);
PrintRectangle(r3);
```
## Another way to write the class member function

```
class CRectangle{
    public:
    int w, h;
    
    void Init(int w_,int h_)
    int Area()   
    int Perimeter()
};
int CRectangle:: Area(){
    return w*h;

}
void CRectangle:: Init(int w_,int h_){
        w = w_; h = h_;
}
int CRectangle::Perimeter(){
        return 2*(w+h);
    }

```
