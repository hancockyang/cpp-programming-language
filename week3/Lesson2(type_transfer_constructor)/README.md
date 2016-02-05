# type transfer constructor
* It is used to transfer the type.
* It can have only one arguement
* It is not a copy constructor.
Example:
```
class Complex{
   public:
      double real, imag;
      Complex(int i){
         cout<<"IntConstructor called"<<endl;
         real = i; imag = 0;
      }
      Complex(double r, double i){
         real = r; imag = r;
      }
};

int main(){
   Complex c1(7,8);     // called the constructor
   Complex c2 = 12;     // pass 12 to intComplex, initialize
   c1 = 9;              // use 9 to call intComplex and pass to c1;
   cout<<c1.real<<","<<c1.imag<<endl;
   return 0;
}
//IntConstructor called
//IntConstructor called
//9,0
```
