# Operator '=' overloaded
* The types at two sides are not equal
  - int variable = Complex object
  - char\* = char object
* We need overload `=`
* `=` can only be overloaded as class member function
Example
* write a allocatable string
  - with a car\* member variable ->  point to the allocatable memory
  - The memory is used to store char ending by '\0'
```
class String{
private:
    char* str;
public:
    String(){str = nullptr;}
    const char* c_str(){return str;}// const use, safe to not change the variable
    char* operator=(const char* s); // const char* is from input
    ~String();
};
```  
Overload the operator:
```
char* String::operator=(const char* s){
    if (str) delete [] str;  // makesure the char* str is not pointing the nullptr
    if (s) {// makesure the s is not nullptr, no problem from copying
        str = new char[strlen(s)+1]; //+1 is for '/0'
        strcpy(str,s);//the char s pointed is copied to the space str pointed
    }
    else
        str = nullptr;
    return str;
}
```
Destructore:
```
String::~String(){
    if (str) {
        delete [] str; //str is not nullptr, delete it
    }
}
```
Main function
```
int main(int argc, const char * argv[]) {
    String s;
    s = "Good Luck,";//s.operator = ("Good Luck,")
    cout<<s.c_str()<<endl;
    //String s2 = "hell!" wrong, because it is decleration not operator
    s = "Shenzhou 8!";
    cout<<s.c_str()<<endl;
    
    return 0;
}
```
## low and deep copy
* low, S1 = S2
  - Copy by pointer
  Example:
  ```
  MyString S1, S2;
  S1 = "this";
  S2 = "that";
  S1 = S2;
  ```
  S1 -> space1: t h i s \0
  S2 -> space2: t h a t \0
  `S1 = S2`
  S1 -> space2
  S2 -> space2
  this will cause
  - space1 does not have pointer
  - when you kill S1 and S2, the space is deleted twice
* deep copy
  - copy by the values the pointer points
  ```
  MyString S1, S2;
  S1 = "this";
  S2 = "that";
  S1 = S2;
  ```
  S1 -> space1: t h i s \0
  S2 -> space2: t h a t \0
  `S1 = S2`
  S1 -> space1: t h a t \0
  S2 -> space2: t h a t \0
  ```
  String & operator=(const String &s){ // const to makesure we just do copy
     if (str) delete [] str;              // same as the last example
     str = new char[strlen(s.str)+1];     // memory space + 1
     strcpy(str,s.str);                   // value copy
     return *this;                        // return the current object using *this
  }
  ```
  - If it still has problem? consider
  ```
  Mystring s;
  s = "Hello";
  s = s;
  ```
  it will cause:
  ```
  if(str) delete[] str;
  str = new char[strlen(s.str)+1];
  strcpy(str, s.str);
  ```
  The variable has been deleted already....
  **Solution this problem**
  ```
  String & operator=(const String &s){ // const to makesure we just do copy
     if (str == s.str) {return *this;}    // if pass the same value, return itself
     if (str) delete [] str;              // same as the last example
     str = new char[strlen(s.str)+1];     // memory space + 1
     strcpy(str,s.str);                   // value copy
     return *this;                        // return the current object using *this
  }
  ```
* Some discussion:
  - void?
  consider a = b = c; same as `a.operator=(b.operator=(c))`. It becomes:
  `a.operator = (void ...) no!
  - String? why string&?
  consider (a=b)=c. this implies reference, and a can be changed
  - Copy constructor?
  consider:
  ```
  string s1;
  s1 = "Hello";
  string s2(s1)// same as s2 = s1;
  ```
  It calls copy constructor and cause low copy.
  ```
  String::String(String&s){
     if (s.str) {
         str = new char[strlen(s.str)+1];
         strcpy(str, s.str);
     }
     else
         str = nullptr;
     }
   }
   ```







  
