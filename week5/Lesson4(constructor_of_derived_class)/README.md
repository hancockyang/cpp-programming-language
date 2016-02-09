# Constructor of Derived Class
* Derived class contains the Base Class
* The constructor of base class will be called before call the constructor of derived class
* The derived class has the follow form:
  constructor(variables):base class name(base class variables){
  }
```
#include <iostream>
using namespace std;
// base class
class Bug{
private:
    int nLegs; int nColor;
public:
    int nType;
    Bug(int legs, int color); // base constructor
    void PrintBug(){};
};

// derived class
class FlyBug: public Bug{
    int nWings;
public:
    FlyBug(int legs, int color, int wings); //derived constructor
};
// wrong way
//FlyBug::FlyBug(int legs, int color, int wings){
//    nLegs = legs;    // base private
//    nColor = color;  // base private
//    nType = 1;       // wrong
//    nWings = wings;
//}

//right way
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs,color){
    nWings = wings;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    FlyBug fb(2,3,4);
    fb.PrintBug();
    fb.nType = 1;
    fb.nLegs = 2; //error, private
    return 0;
}
```
`FlyBug fb(2,34)`
* When the complier creates the constructor of the derived class:
  - need to call the constructor from base class to initialize the members derived from base class
  - base constructor always be call before the derived constructor
* How to call the base constructor
  - Explicit (see the bug code example above)
  derived:: derived(arg\_derived-list):base(arg\_base-list)
  - Implicit
    - we can neglect the base constructor
    - the system will call the default base constructor
* Destructor will call the derived first and then base class
Example:
```
class Base{
public:
    int n;
    Base(int i):n(i){
        cout<<"Base "<<n<<" constructed"<<endl;
    }
    ~Base(){cout<<"Base "<<n<<" destructed"<<endl;}
};

class Derived:public Base{
public:
    Derived(int i):Base(i){
        cout<<"Derived constructed"<<endl;
    }
    ~Derived(){
        cout<<"Derived destructted"<<endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    //FlyBug fb(2,3,4);
    //fb.PrintBug();
    //fb.nType = 1;
    //fb.nLegs = 2; //error, private
    Derived Obj(3);
    
    return 0;
}
```
* The heritant has class as member variable
```
class Skill{
public:
    Skill(int n){}
};
// base class
class Bug{
private:
    int nLegs; int nColor;
public:
    int nType;
    Bug(int legs, int color); // base constructor
    void PrintBug(){};
};

Bug::Bug(int legs, int color):nLegs(legs),nColor(color){}
// derived class
class FlyBug: public Bug{
    int nWings;
    Skill sk1,sk2;
public:
    FlyBug(int legs, int color, int wings); //derived constructor
};
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs,color),sk1(5),sk2(color){
    nWings = wings;
}
```
