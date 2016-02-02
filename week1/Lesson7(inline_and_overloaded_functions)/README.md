##Inline and overloaded functions
# Inline functions 
inline functions are a lot like a placeholder. Once you define an inline function, using the `inline` keyword, whenever you can call that function the compiler will replace the function call with the actual code from the function. It is good for small functions for speed up.
```
inline int Max(int a, int b)
{
   if(a>b) return a;
   return b;
}
```
# Overloaded functions
C++ allows specification of more than one function of the same name in the same scope. These are called overloaded
functions and are descrived in detail in *Overloading*. Overloaded functions enable programmers to supply different
sematics for a function depending on the types and numbers of arguments
Example:
```
int Max(double f1, double f2){}
int Max(int n1, int n2){}
int Max(int,n1, int n2, int n3){}
```
-(1) int Max(double f1, double f2){}
-(2) int Max(int n1, int n2){}
-(3) int Max(int,n1, int n2, int n3){}
```
Max(3.4,2.5);   //(1)
Max(2,4);       //(2)
Max(1,2,3);     //(3)
Max(3,2.4);     //error
```
