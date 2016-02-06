# Const object, Const member function and Const &
## const object
* The form is `const class object`
  1. This object can't be changed after initialization
```
class Demo{
   private:
      int value;
   public:
      void SetValue(){   }
};

const Demo obj; //const obj
```
## const member function
* The form is  `function const`
  1. const member function can't change the member arguement (not static)
  2. const member function can't call the member function of the same class
Example:
```
class Sample
{
   public:
      int value;
      void GetValue() const;
      void func(){};
      Sample(){}
};

void Sample::GetValue() const
{
   value = 0;//wrong, reason 1
   func();//wrong, reason 2
}

int main(){
   const Sample o;
   o.value = 100;   //error, const object reason 1
   o.func();        //error, const object reason 1 
   o.GetValue();    //right, const object can do const member function
   return 0;
}
```
## Overloading
Two memeber function that have the same name and arguements, but one with `const`, one withou. It is overloaded.
Example:
```
class CTest{
   private:
      int n;
   public:
      CTest() {n = 1;}
      int GetValue() const {return n;}
      int GetValue() {return 2*n;}
};

int main(){
   const CTest objTest1;
   CTest objTest2;
   cout<<objTest1.GetValue()<<", "<<objTest2.GetValue();
   return 0;
}
```
## Const class &
When the object is the arguement of one function, usually the complier needs to call the copy constructor. It is
inefficient. Pointer makes it not easy to read. So here we use &.
Example:
```
class Sample{
...
};
void PrintObj(Sample & o)
{
...
}
```
There is a problem that the function may potentially change the arguement in the class. We use the const &.
Example:
```
class Sample{
...
};
void PrintObj(const Sample & o)
{
...
}
```
**The example here confused with overloading and it vilade the const to const rule**
