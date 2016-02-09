# Inheritance and composition relations:
There are 3 relations between two classes (nothing, inheritance, and compostion)
* Inheritance (is):
  - Base class A, B is base class A's derived class
  - Object is class B, then it is also a class A
* Composition (has):
  - Class C has member variable k, k is the object of Class D, then C and D is composite
  - Class D is Class C's feature or composor.
## Inheritance:
* Class Cman for man
* Now need Class CWoman
* We can see man and woman have common features
* Can CWoman derived from Cman?
* The answer is no.
* It is not inheritance

The right way to do is:
- Write a Class CHuman and 
- Class CMan and CWoman are derived from CHuman.
## Compsition:
In geometry, we need write Class CPoint and Class CCircle:
The following  is an wrong example. The inheritance relation is not right (circle is not point)
```
class CPoint
{
   double x, y;
};

class CCircle:public CPoint
{
   double r;
};
```
We should use compsition, the center is Class CPoint, means the CCircle includes Class CPoint
```
class CPoint
{
   double x, y;
};

class CCircle:public CPoint
{
   double r;
   CPoint center; // friend!
};
```
More example:
* Dogs example, we need Class owner, and Class dog
* Dog has owner, owner can has more than one dogs or none

- One proposal:
```
class CDog;
class CMaster{
   CDog dogs[10];

};
class CDog
{
   CMaster m;
};
```
**Wrong!** CDog is in CMaster, CMaster is in CDog! 
- Another solution.
```
class CDog;
class CMaster{
   CDog *dogs[10];

};
class CDog
{
   CMaster m;
};
```
It solved the problem. But, two dogs shares the same master info, you change one class CDog info about its master would not change the other class CDog with the same master's info!
- A better solution:
```
class CMaster;

class CDog
{
   CMaster *pm;
};

class CMaster{
   CDog dogs[10];

};
```
Master has 10 dogs array, each dog has pointer points to its master, look fine. But, dog is not feature of master, and
dogs are bonded to master class, we can't modify the dog class directly.
- Right way to do:
```
class CMaster;

class CDog
{
   CMaster *pm;
};

class CMaster{
   CDog *dogs[10];

};
```
Master has more than one dogs, so he has pointers point to his dogs. Dog has one master, it has pointer points to it
master. Master can use pointer to find his dog. Dog can do the similar. Now we can modify all the class independently.

