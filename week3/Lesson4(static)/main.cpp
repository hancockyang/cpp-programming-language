//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/4/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CRectangle
{
private:
    int w, h;
    static int nTotalArea; // statc member
    static int nTotalNumber;
public:
    CRectangle(int w_, int h_);
    CRectangle(CRectangle &r);
    ~CRectangle();
    static void PrintTotal(); //static function
};

CRectangle::CRectangle(int w_, int h_)
{
    w = w_;
    h = h_;
    nTotalNumber ++;
    nTotalArea += w * h;
}

CRectangle::CRectangle(CRectangle &r)
{
    w = r.w; h = r.h;
    nTotalNumber ++;
    nTotalArea += w*h;
}

CRectangle::~CRectangle()
{
    nTotalNumber --;
    nTotalArea -= w * h;
}

int CRectangle::nTotalArea = 0;   // static has to be declared outside
int CRectangle::nTotalNumber = 0;

void CRectangle::PrintTotal()
{
    cout<<nTotalNumber<<", "<<nTotalArea<<endl;
}

int main(int argc, const char * argv[]) {
    CRectangle r1(3,3), r2(2,2);
    //cout<<CRectangle::nTotalNumber;//Wrong, nTotalNumber is private
    CRectangle::PrintTotal();
    r1.PrintTotal();
    
    return 0;
}
