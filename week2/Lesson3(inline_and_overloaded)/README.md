# inline and overloaded function in class
## Inline
* `inline` + member function
* put the function all in the class
```
class B{
   inline void func1();  // first method
   void func2()          // 2nd method
   {
   };
};

void B::func1(){}
```
## overloaded and default
```
#include <iostream>
using namespace std;
class Location{
   private:
      int x, y;
   public:
      void init(int x = 0, int y = 0);
      void valueX(int val) {x = val;}
      int valueX(){return x;}
};


void Location:: init(int X, int Y){
   x = X;
   y = Y;
}

int main(){
   Location A;
   A.init(5);        // use default value of y = 0;
   A.valueX(5);      // void valueX(int val)
   cout<<A.valueX()<<endl; // int valueX()
   
   return;
}

```
