# \>\> and \<\< overload
*Question?*
* how does `cout<<5<<"this";` work
* what is `cout`, why can `<<` act on `cout`?
- `cout` is defined in `iostream`
  It is object of `ostream` class
- `<<` can work on `cout` is because it is overloaded in `iostream`.
- Think, what type of overload can make this work
  `cout<<5;` and `cout<<"this";`
## We can possibily do..
* overload the \<\< as the member function of class `ostream` for `cout<<5`:
```
void ostream::operator<<(int n) // n is for 5
{
   ...
   return;
}
```
`cout<<5;` is `cout.operator<<(5);`
`cout<<"this;` is `cout.operator<<("this");'
* How can we make `cout<<5<<"this";` work
The return value has to be `cout`, so the above can be modified:
```
ostream & ostream::operator<<int(n){
   ...
   return *this;
}
```
`this` is pointing the object the memeber function in on, then `\*this` is `cout`. This function has return value of
being the reference
type `ostream`, so the function has return value the reference of `cout`.Similarly,
```
ostream &ostream::operator<<(const char* s)
{
   ...
   return *this
}
```
Thus, the `cout<<5<<"this";` is `cout.operator<<(5).operator<<("this")`.
* Assume the following code would output "5hello", how can we finish this?
```
class CStudent{
   public: int nAge;
};
int main(){
   CStudent s;
   s.nAge = 5;
   cout<< s<<"hello";
   return 0;
}
```
`cout` is `ostream` object. `ostream` is written in `iostream`, we cant add member function, now we can only overload
this to be a global function.(for `cout<<\s`)

```
ostream & operator<<(ostream &o, const CStudent & s){
   o<<s.nAge;
   return o;
}
```
**Here use `return o` instead of `return \*this`. It is because << has two inputs.**
Example:
Assume c is objec of class complex, now we want write `cout<<\c;` so that we can output result as `a+bi`, write
`cin>>\c`, the program can accept inputs as `a+bi` and make c.real = a, c.imag = b.
* main function
```
int main(){
    Complex c;
    int n;
    cin>>c>>n;
    cout<<c<<","<<n;
    return 0;
}
```
The input:

13.2+133i 87

The output:

13.2+133i. 87
* overload << operator
```
ostream & operator<<(ostream &os, const Complex & c){
    os<<c.real<<"+"<<c.imag<<"i";
    return os;
}
```
* overload >> operator
```
istream &operator>>(istream &is, Complex &c)
{
    string s;
    is>>s;//write "a+bi" as string to is
    int pos = s.find("+",0);
    string sTmp = s.substr(0, pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos+1, s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return is;
}
```
