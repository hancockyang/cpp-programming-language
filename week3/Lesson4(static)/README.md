# Static
* `static` keyword
Example:
```
class CRectangle
{
private:
    int w, h;
    static int nTotalArea; // statc member
    static int nTotalNumber;
public:
    CRectangle(int w_, int h_);
    ~CRectangle();
    static void PrintTotal(); //static function
};
```
* `static` member is shared by all the objects. It has only one.
* `sizeof` operator is not calculating the `static`.
Example:
```
class CMyclass{
   int n;
   static int s;
};
sizeof(CMyclass)//4
```
* `static` function is not on any objects
* `static` can be called without object
   1. Class::member: `CRectangle::PrintTotal();`
   2. Object.member: `CTectangle r; r.PrintTotal();`
   3. Pointer -> member: `CRectangle* p = &r; p->PrintTotal();`
   4. Ref.member: `CRectangle &ref = r; int n = ref.nTotalNumber;`
* `static` is global variable/function of the class
* It is designed to be easy to use and understand
        Example: total number/area of the rectangles
Example:
```
#include <iostream>
using namespace std;
class CRectangle
{
private:
    int w, h;
    static int nTotalArea; // statc member
    static int nTotalNumber;
public:
    CRectangle(int w_, int h_);
    ~CRectangle();
    static void PrintTotal(); //static function
};

CRectangle::CRectangle(int w_, int h_)
{
    w = w_;
    h = h_;
    nTotalNumber ++;
    nTotalArea += w * h;
}

CRectangle::~CRectangle()
{
    nTotalNumber --;
    nTotalArea -= w * h;
}
int CRectangle::nTotalArea = 0;   // static has to be declared outside
int CRectangle::nTotalNumber = 0;

void CRectangle::PrintTotal()
{
    cout<<nTotalNumber<<", "<<nTotalArea<<endl;
}

int main(int argc, const char * argv[]) {
    CRectangle r1(3,3), r2(2,2);
    //cout<<CRectangle::nTotalNumber;//Wrong, nTotalNumber is private
    CRectangle::PrintTotal();
    r1.PrintTotal();
    
    return 0;
}
```
**Note: in the static function, you can't call normal variables or cll normal function**
```
void CRectangle::PrintTotal()
{
    cout<<w<<nTotalNumber<<", "<<nTotalArea<<endl;//wrong
}
```
## The previous example has flaw
This is because of copy constructor.
* Call the function has the declared arguement as object of the CRectangle class
* Call the function with the return value as object of the CRectangle class
* Temperory object

**Write copy constructor**
```
CRectangle::CRectangle(CRectangle &r)
{
    w = r.w; h = r.h;
    nTotalNumber ++;
    nTotalArea += w*h;
}
```
