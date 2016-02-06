# Overload the operator to be friend
Operator can be overloaded to be
- normal function 
- class memeber function
Overload operator to be friend can be found:
- the memeber functions are not enough for all the use
- normal function can't call the private memeber of a class
Example
```
#include <iostream>
using namespace std;

class Complex{
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i){};
    Complex operator+(double r);
};

Complex Complex::operator+(double r){// can do c+5
    return Complex(real+r, imag);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
```
This can explain:
```
Complex c;
c = c + 5;
```
But error with:
```
c = 5 + c;
```
Now we can use:
```
Complex operator+(double r, const Complex &c){
    return Complex(c.real+r, c.imag);
}
```
as common function, but we also need declare it as friend of class Complex
```
class Complex{
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i){};
    Complex operator+(double r);
    friend Complex operator+(double r, const Complex &c);
    
};
```

