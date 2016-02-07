# ++ and -- overload
* Prefix and surfix are different `++i` is diferent from `i++`.
## Prefix can be use as *unioperator* `++i`
- Overloaded as member function
  1. T operator++();
  2. T operator--();
- Overloaded as global function
  1. T operator++(T);
  2. T operator--(T);
- ++obj, obj.operator++(), operator++(obj) can call the functions above
## Surfix is *bioperator*
- need write one more arugment
- Overloaded as member functon
  1. T operator++(int);
  2. T operator--(int);
- Overloaded as global function
  1. T operator++(T, int);
  2. T operator--(T, int);
- obj++, obj.operator++(0), operator++(obj,0) can call the functions above

Example:
* main function
```
int main(int argc, const char * argv[]) {
    CDemo d(5);
    cout<<(d++)<<","; //same as d.operator++(0);cout d first then ++
    cout<<d<<",";
    cout<<(++d)<<","; //same as d.operator++();
    cout<<d<<endl;
    cout<<(d--)<<","; //same as operator--(d,0);
    cout<<d<<",";
    cout<<(--d)<<";"; //same as operator--d(d);
    cout<<d<<endl;
    return 0;
}

```
output:

5,6,7,7

7,6,5,5
* CDemo class
```
class CDemo{
private:
    int n;
public:
    CDemo(int i = 0):n(i){}              //constructor
    CDemo operator++();                  //prefix
    CDemo operator++(int);               //surfix
    operator int(){return n;}            //force int overloaded
    friend CDemo operator--(CDemo &);    //prefix
    friend CDemo operator--(CDemo&, int);//surfix
};
```
* prefic++ & surfix++ (*member function*)
```
CDemo CDemo::operator++(){//prefix
    n++;
    return *this;
}

CDemo CDemo::operator++(int k){//surfix
    CDemo tmp(*this); // record the current value
    n++;
    return tmp;
}
```
* prefix-- & surfix-- (*global function*)
```
CDemo operator--(CDemo &d){//prefix
    d.n--;
    return d;
}

CDemo operator--(CDemo &d, int){//surfix
    CDemo tmp(d);//record the current value
    d.n--;
    return tmp;
}
```
* Also note that
```
operator int(){return n;} 
```
  - `int` has be overloaded as forcing type converter
  ```
  Demo s;
  (int) s; // same as s.int()
  ```
  - forcing type converter:
    - You cant define return type
    - The return type is the type it is forcing
## General rules
* You can't find the new operator
* The overloaded operator has to follow the common sense
* Overloaded operator can't overwrite th priority
* Some of the operators can't be overloaded: ",",".","::","?:",sizeof
* "()","[]","->","=" have to declare to be the *class memeber* function

