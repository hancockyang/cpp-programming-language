# Base Class and Inheritant Class shared the same name and Protect
## Bass Class and Inheritant class share the same name (member)
```
class base{
   int j;
public:
   int i;
   void func();
};

class derived:public base{
public:
   int i;
   void access();
   void func();
};
```
Derived class and base class have the same member variable `i` and member function `func`. More detailed example:
```
void derived:: access()
{
    //j = 5;     // wrong, base private
    i = 5;       // derived i
    base:: i = 5;// base i
    func();      // derived func()
    base::func();// base func()
}

int main(int argc, const char * argv[]) {
    derived obj;
    obj.i = 1;      // derived
    obj.base::i = 1;// base
    std::cout << "Hello, World!\n";
    return 0;
}
```
Obj has the memory: bass::j, bass::i, and i
*note: we usually use different member variable names for base and derived class obj*
## Public, private, protected
* base class member with `private` keyword can be called:
  - Base member function
  - Base friend fucntion
* base class member with `public` keyword can be called:
  - Base member function
  - Base friend fucntion
  - Derived member function
  - Derived friend function
  - Other functions
* base class member with `protected` keyword can be called:
  - Base member function
  - Base friend fucntion
  - Derived member function can only cann the current object



