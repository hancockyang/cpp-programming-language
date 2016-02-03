# Class accessible
## Keyword
* `private`  : can be accessed by only the local class memebers
* `public`   : global
* `protected`: protected member
Example
```
class className{
   private:
      local
   public:
      global
   protected:
      protected
};
```
## Defult is local: 'private'
Example
```
class Man{
      int nAge;       // local
      char szName[20];// local
   
   public:
     void SetName(char* Name){
        strcopy(szName, Name);
     }
};
```
## The accessibility of class members
* In the class
..1. All the memebers
..2. All the memebers of the same class
* Outside the class
...Only the public member
Example
```
#include <iostream>
using namespace std;

class CEmployee{
private:
    char szName[30];
public:
    int salary;
    void setName(const char* name);
    void getName(char* name);
    void averageSalary(CEmployee e1, CEmployee e2);
};

void CEmployee::setName(const char* name){
    strcpy(szName, name);//ok
}
void CEmployee::getName(char* name){
    strcpy(name,szName);//ok
}
void CEmployee::averageSalary(CEmployee e1, CEmployee e2){
    salary = (e1.salary + e2.salary)/2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    CEmployee e;
    //strcpy(e.szName, "Tom123456789"); //wrong, szName is local
    e.setName("Tom");
    char* name;
    e.getName(name);
    cout<<name<<endl;
    e.salary = 5000;
    return 0;
}
```
