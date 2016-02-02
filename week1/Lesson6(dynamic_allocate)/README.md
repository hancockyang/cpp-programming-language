#Dynamic allocate
## You can use it to allocat a variable by P = new T
T is any type. P is  T\* type pointer. It will open sizeof(T) space and put the initial address to the P;
```
int* pn;
pn = new int;
*pn = 5;
```
## You can allocat array by P = new T[N]
```
int* pn;
int i = 5;
pn = new int[i*20];
pn[0] = 20;
pn[100] = 30;//wrong
```
## `new` operator had return value
```
new T;
new T[N];
```
the return value is type of T\*
`int* p = new int'`
## Use `delete` to release the memory
```
int* p = new int;
*p = 5;
delete p;
delete p; //wrong can't be deleted twice
```
## Use `delete[]` to release array
```
int* p = new int[20];
p[0] = 1;
delete[] p;
```
