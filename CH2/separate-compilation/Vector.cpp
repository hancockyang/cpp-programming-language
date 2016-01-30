#include"Vector.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Vector:: Vector(int s)
       :elem{new double[s]},sz{s}
{
    //if (s<0) throw length_error{}; not working
    
    
}

double& Vector:: operator[](int i)
{
    if (i<0 || size()<=i) throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size()
{
    return sz;
}

void test()
{
    try{
        Vector v(-27);
    }
    catch(length_error){cout<<"length_erro\n";}
    catch(bad_alloc) {}
}