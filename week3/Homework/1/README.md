# 1
Input:
NONE

Output:
4,6

```
#include <iostream>
using namespace std;
class A {
        int val;
    public:
        A(int n) { val = n; }
        int GetVal() { return val; }
};
class B: public A {
    private:
        int val;
    public:
        B(int n):
// your code goes here
        { }
        int GetVal() { return val; }
};
int main() {
    B b1(2);
    cout << b1.GetVal() << "," << b1.A::GetVal() << endl;
    return 0;
}
```
