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
