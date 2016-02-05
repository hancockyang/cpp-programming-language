#Friend
* Friend function
* Friend class
## Friend Function
A friend function of one class can call the private member of that class
```
class CCar;
class CDriver{
   public:
      void ModifyCar(CCar* pCar);
};

class CCar{
   private:
      int price;
   friend int MostExpensiveCar(CCar cars[], int total);// can call private in CCar
   friend void CDriver::ModifyCar(CCar* pCar);         // can call private in CCar
};

void CDriver::ModifyCar(CCar* pCar)
{
   pCar -> price += 1000;
}

int MostExpensiveCar(CCar cars[], int total)
{
   int tmpMax = -1;
   for(int i = 0; i<total;++i)
      if(cars[i].price > tmpMax)
         tmpMax = cars[i].price;
   return tmpMax;
}

int main()
{
   return 0;
}
```
## Friend function in Class (constructor and destructor)
```
class B{
   public:
      void function();
};
class A{
   friend void B::function(); // class A can call function which in B??
};
```
## Friend Class
A is friend of B. A can call B's private
```
class CCar{
   private:
      int price;
      friend class CDriver;
};
class CDriver{
   public;
      CCar mycar;
      void ModifyCar(){
         myCar.price += 1000;
      }
};

int main(){return 0;}
```
**Note: Frind can be passed**

