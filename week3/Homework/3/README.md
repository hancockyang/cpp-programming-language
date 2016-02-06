# 3
OUTPUT
10

```
#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// your code goese here
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}```
