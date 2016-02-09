# Inheritance of `public` and its compatibilty
```
class base{};
class derived: public base{};
base b;
derived d;
```
1. Derived can be equal to base object
   `b = d;`
2. Derived can initialize the base object reference
   `base &br = d;`
3. Derived address can be set to the base object's pointer
   `base *pb = &d;`
**They are not true if not keyword `public`. (`privat` or `protected`)**
# Direct inheritance and indirect inheritance
* Base A -> derived B ->  derived C -> derived D
  - A is B's direct base
  - B is C's direct base, A is C's indirct base
  - C is D's direct base, A and B is D's indirct base
  - ...
* It is only nessecary to show the direct base when declare a derived class
  - Derived class would inheritate it's direct base class
  - Derived class includes:
    1. Its own member,
    2. Its direct base member,
    3. All the indirect base member.
```
#include <iostream>
using namespace std;

class Base{
public:
    int n;
    Base(int i):n(i){
        cout<<"Base "<<n<<" constructed"<<endl;
    }
    ~Base(){
        cout<<"Base "<<n<<" destructed"<<endl;
    }
};
class Derived: public Base{
public:
    Derived(int i):Base(i){
        cout<<"Derived "<<n<<" constructed"<<endl;
    }
    ~Derived(){
        cout<<"Derived "<<n<<" destructed"<<endl;
    }

    
};
class MoreDerived: public Derived{
public:
    MoreDerived():Derived(4){
        cout<<"Derived "<<n<<" constructed"<<endl;
    }
    ~MoreDerived(){
        cout<<"Derived "<<n<<" destructed"<<endl;
    }
    
    
};


int main(int argc, const char * argv[]) {
    MoreDerived Obj;
    return 0;
}
```

