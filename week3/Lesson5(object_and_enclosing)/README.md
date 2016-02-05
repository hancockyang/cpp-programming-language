# Member Object and Enclosing

* A member argument in one class is object of another class
* The class contains the member argument is called *Enclosing*.
Example:
```
class CTypre{
   private:
      int radius;
      int width;
   public:
      CTypre(int r, int w): radius(r), width(w) { } //initialization list
};

class CEngine{

};

class CCar{ // class CCar is enclosing
   private:
      int price;
      CTypre typre;
      CEngine engine;
   public:
      CCar(int p, int tr, int tw); 
}

CCar::CCar(int p, int tr, int w):prive(p), tyre(tr,w){

};

in main(){
   CCar car(200000,17, 225);
   return 0;
}

```
* Enclosing class has to define the contructor
   `CCar car;//error`
  1. Complier dose not know how to initialize `car.typre`
  2. `car.engine` is fine
* Use initialization list
class name:: (argument list):argument1(variable),argument2(variable)...
{
...
}
* Initialization list
  1. can be used for any expression
  2. function/argument/expression
* Call order
  - In enclosing 
    - initial member object constructor first
    - then enclosing constructor
  - Member object's constructor
    - the order is the same as declaration in the member object
    - not relevant to the order in the initialization list
Example:
```
class CTyre{
  public:
     CTyre(){ cout<<"CTyre constructor"<<endl;}
     ~CTyre(){ cout<<"CTyre destructed"<<endl;}
};

class CEngine{
  public:
     CEngine(){ cout<<"CEngine constructor"<<endl;}
     ~CEngine(){ cout<<"CEngine destructed"<<endl;}
};
class CCar{
   private:
      CEngine engine;
      CTyre tyre;
   public:
      CCar(){cout<<"CCar constructor"<<endl;}
      ~CCar(){cout<<"CCar destructor"<<endl;}
};

int main(){
   CCar car;
   return 0;
}
```
