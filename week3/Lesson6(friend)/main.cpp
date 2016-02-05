//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CCar;
class CDriver{
public:
    void ModifyCar(CCar* pCar);
};

class CCar{
private:
    int price;
    friend int MostExpensiveCar(CCar cars[], int total);// can call private in CCar
    friend void CDriver::ModifyCar(CCar* pCar);         // can call private in CCar
    //friend class CDriver;// makes CCar is friend of class CDriver, so CDriver class can call CCar function
};

void CDriver::ModifyCar(CCar* pCar)
{
    pCar -> price += 1000;// can call private in CCar
}

int MostExpensiveCar(CCar cars[], int total)
{
    int tmpMax = -1;
    for(int i = 0; i<total;++i)
        if(cars[i].price > tmpMax)// can call private in CCar
            tmpMax = cars[i].price;
    return tmpMax;
}

int main()
{
    return 0;
}
