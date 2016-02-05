# Copy constructor
* It can have only one arugement: `X::X(X&)` or `X::X(const X &)`
* Complier will generate a copy constructor if not specified
Example:
```
class Complex{
   private:
      double real, imag;
};
Complex c1;     // call the default (non arguement) constructor
Complex c2(c1); // call the default copy constructor, c2 is a copy of c1
```
## How to define your own copy constructor
```
class Complex{
   private:
      double real, imag;
      Complex(){}                          // constructor
      Complex(const Complex &c ){          // copy constructor
         real = c.real;
         imag = c.imag;
         cout<<"Copy Constructor called";
       }
};
Complex c1;     // call the constructor
Complex c2(c1); // call the copy constructor, output ""
```
This example shows user defined copy constructor does not have to do the copy job
## Can't have `X::X(X)`
```
class CSample{
   CSample(CSample c){
   }//wrong
};
```
## It is used in the following three situations
* Used to initialize the other object of the same class
Two Examples:
`Complex c2(c1);` and `Complex c2 = c1;`
* If one function has arguement is the object of class A, then the copy constructor of class A will be called if that
  function is called
Example:
```
class A
{
   public:
      A(){};
      A(A & a){
         cout<<"Copy constructor called"<<endl;
      }
};
void Func(A a1){}
int main(){
   A a2;
   Func(a2);
   return 0;
}
```
* If the return value of a function is object of class A, then the copy constructor of class A will be call when the
  function returns (it does not call copy constructor, it calls constructor!)
Example
```
class A{
   public:
      int v;
      A(int n){v = n;};
      A(const A &a){
         v = a.v;
         cout<<"Copy constructor called"<<endl;
      }
};
A Func(){
   A b(4);
   return b;
}
int main(){
   cout<<Func().v<<endl; // this function calls copy constructor, which initialize v = 4 for this class, and function is
   initialized as class A
   return 0;
}
```
// copy constructor called
// 4
