# `This` pointer
Example:
```
class CCar{
   public:
     int price;
     void SetPrice(int p);
};
void CCar::SetPrice(int p)
{ price = p;}

int main()
{
   CCar car;
   car.SetPrice(20000);
   return 0;
}
```
To C
```
struc CCar{
   int price;
};
void SetPrice(struct CCar* this, int p){ 
   this -> price=p;
}
int main(){
   struc CCar car;
   setPrice(&car, 20000);
   return 0;
}
```
`this` pointer:
* Pointer to the object the function is acting on
Example:
```
class Complex{
   public:
      double real, imag;
      void Print(){cout<<real<<", "<<imag<<endl;}
      Complex(double r, double i): real(r),imag(i)
      {   }
      Complex AddOne(){
         this -> real++; //same as real++
         this -> Print();//same as Print
         return *this;
      }
};

int main(){
   Complex c1(1,1), c2(0,0);
   c2 = c1.AddOne();
   return 0;
}
```
One more example:
```
class A
{
   int i;
   public:
      void Hello(){cout<<"Hello"<<endl;}
};

int main()
{
    A* p = NULL;
    p -> Hello();
}
```
Wrong example:
```
class A
{
   int i;
   public:
      void Hello(){cout<<i<<"Hello"<<endl;}  // this point to null, null.i is not right
};

int main()
{
    A* p = NULL;
    p -> Hello();
}
```
**Note: `this` pointer cant point to `static`**

