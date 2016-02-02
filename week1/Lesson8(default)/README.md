# Default
from right to left several arguments can be neglected by using default. It allows a good expanding the function in
future.
```
void func(int x1, int x2 = 2, int x3 = 3){}

func(10)     //= func(10,2,3)
func(10,8)   //= func(10,8,3)
func(10,,8)  //= error
```
