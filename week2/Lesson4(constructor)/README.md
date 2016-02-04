# Constructor
* It can't have return value.
* It is in `class`. It is used by `class` and initialized.
* `class` can have more than 1 constructor.
## Why constructor
* It will be initialized by complier.
## Example
```
class Complex{
   private:
      double real, imag;
   public:
      void Set(double r, double i);
};// complier will generate default constructor

Complex cl; // the default constructor is used
Complex* pc = new Complex;// the default constructor is used
```
Use constructor
```
class Complex{
   private:
      double real, imag;
   public:
      void Set(double r, double i);
      Complex::Complex(double r, double i = 0);
};
//constructor:
Complex::Complex(double r, double i){
   real = r; imag = i;
}

Complex cl; //wrong, no arguement
Complex* pc = new Complex;// wrong, no arguement
Complex cl(2);//ok, the second arguement is optional, i = 0
Complex cl(2,4), c2(2,5);
Complex* pe = new Complex(3,4);
```
## Overloaded constructor

```
class Complex{
   private:
      double real, imag;
   public:
      void Set(double r, double i);
      Complex::Complex(double r, double i = 0);
      Complex::Complex(double r);
      Complex::Complex(Complex c1, Complex c2);

};
Complex::Complex(double r, double i){
   real = r; imag = i;
}
Complex::Complex(double r){
   real = r; imag = 0;
}
Complex::Complex(Complex c1, Complex c2){
   real = c1.real + c2.real;
   imag = c1.imag + c2.imag;
}

Complex cl(3), c2(1,0), c3(c1,c2);
//c1 = {3,0},c2 = {1,0}, c3 = {4,0};

```
## Constructor in array
```
class CSample{
   int x;
   public:
      CSample(){
         cout<<"Constructor 1 Called"<<endl;
      }
      CSample(int n){
         x = n;
         cout<<"Constructor 2 Called"<<endl;
      }
};

in main(){
   CSample array1[2];
   cout<<"step1"<<endl;
   CSample array2[2] = {4,5};
   cout<<"step2"<<endl;
   CSample array3[2] = {3}
   cout<<"step3"<<endl;
   CSample* array4 = new CSample[2];
   delet []array4
   return 0;
}
//Constructor 1 Called
//Constructor 1 Called
//step1
//Constructor 2 Called
//Constructor 2 Called
//step2
//Constructor 2 Called
//Constructor 1 Called
//step3
//Constructor 1 Called
//Constructor 1 Called
```
More example
```
class Test{
   public:
      Test(int n){}        //(1)
      Test(int n, int m){} //(2)
      Test(){}             //(3)
};
Test array1[3] = {1, Test(1,2)}
//use (1),(2),(3) to initialize
Test array2[3] = {Test(2,3), Test(1,2),1};
//use (2),(2),(1) to initialize
Test* parray[3] = {new Test(4), new Test(1,2)}
//use (1),(2) to initialize, parray[2] is just a pointer
```
