# Destructor
## Review of Constructor
* It is one of the member function
* Its name is the same as the class name
* It can have arguement, but it cant have return value
* You can have more than one constructor
## Destructor
* It is one of the member function
* Its name is the same as the class name, but `~` in front of its name
* It dose not have arguement and return value
* Class can only have one Destructor
* It will be called automatically when you `delete` one object. It release the memory
* Complier will generate a default destructor if user dose not define. It will not reals any variable user defined
Example:
```
class String{
   private:
      char* p;
   public:
      String(){
         p = new char[10];
      }
      ~String();
};
String::~String(){
   delete []P;
}
```
## Destructor and Array
* very element in the array will can destructor 
Example:
```
class Ctest{
   public:
      ~Ctest(){ cout<<"destructor called"<<endl;}
};

int main(){
   Ctest array[2];
   cout<<"End Main"<<endl;
   return 0;
}
//End Main
//destructor called
//dectructor called
```
* `delete` can the destructor
Example:
```
Ctest* pTest;      
pTest = new Ctest;   // constructor called
delete pTest;        // destructor called

//------------------
pTest = new Ctest[3] // constructor called 3 times
delete []pTest;      // destructor called 3 times
```
## How to use constructor and destructor?
Example:
```
class Demo{
   int id;
   
   public:
      Demo(int i)
      {
         id = i;
         cout<<"id = "<<id<<" Constructed"<<endl;
      }
      ~Demo()
      {
         cout<<"id = "<<id<<" Destructed"<<endl;
      }
};

Demo d1(1);
void Func(){
   static Demo d2(2);
   Demo d3(3);
   cout<<"Func"<<endl;
}

int main(){
   Demo d4(4);
   d4 = 6;
   cout<<"main"<<enld;
   { Demo d5(5);   }
   Func();
   cout<<"main ends"<<endl;
   return 0;
}
```
output:
`id = 1 Constructed`
`id = 4 Constructed`
`id = 6 Constructed`
`id = 6 Destructed`
`main`
`id = 5 Constructed`
`id = 5 Destructed`
`id = 2 Constructed`
`id = 3 Constructed`
`Func`
`id = 3 Destructed`
`main ends`
`id = 6 Destructed`
`id = 2 Destructed`
`id = 1 Destructed`




