# Operator Overloading Concept
* Also known as ad-hoc polymorphism
* Overloads the default operator
* Makes the same operator on different data structure
## Objective
* Expand the default operator to different data structures and classed
## The same operator on different data structures
  - (5, 10i) + (4, 8i) = (9, 18i)
  - 5 + 4 = 9
## It is in fact a overloaded function
type operator operator symbole (arguement list)
* Overloaded as function
```
#include <iostream>
using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0){
        real = r;
        imaginary = i;
    }
    double real;
    double imaginary;
};

Complex operator+(const Complex &a, const Complex &b){
    return Complex(a.real+b.real, a.imaginary+b.imaginary);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Complex a(1,2), b(2,3), c;
    c = a + b;
    cout<<c.real<<", "<<c.imaginary<<endl;
    return 0;
}
```
* Overloaded as class memeber function
```
#include <iostream>
using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0):real(r), imaginary(m){ }
    Complex operator+ (const Comple &);
    Complex operator- (const Comple &);

private
    double real;
    double imaginary;
};
Complex Complex::operator+(const Complex &operand2){
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2){
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Complex a(1,2), b(2,3), c;
    c = a + b;
    cout<<c.real<<", "<<c.imaginary<<endl;
    return 0;
}

```
