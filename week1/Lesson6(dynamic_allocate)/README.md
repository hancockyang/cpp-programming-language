#Dynamic allocate
## You can use it to allocat a variable by P = new T
T is any type. P is  T\* type pointer. It will open sizeof(T) space and put the initial address to the P;
```
int* pn;
pn = new int;
*pn = 5;
```
