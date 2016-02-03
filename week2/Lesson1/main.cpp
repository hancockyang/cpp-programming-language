//
//  main.cpp
//  part1
//
//  Created by hankang yang on 2/1/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
using namespace std;
class CRectangle{
    public:
    int w, h;
    
    void Init(int w_,int h_){
        w = w_; h = h_;
    }
    int Area(){
        return w*h;
    }
    int Perimeter(){
        return 2*(w+h);
    }


};
void PrintRectangle(CRectangle &r){
    cout<<r.Area()<<","<<r.Perimeter()<<endl;
}

int main(int argc, const char * argv[]) {
    int w,h;
    CRectangle r, r1, r2;
    CRectangle* p1,* p2;
    CRectangle &rr = r2;
    p1 = &r1;
    p2 = &r2;
    cin>>w>>h;
    r.Init(w, h);
    cout<<r.Area()<<endl<<r.Perimeter()<<endl;
    r1.w = 5;
    r2.Init(3,4);
    p1 -> w = 5;
    p2 -> Init(3, 4);
    cout<<r1.w<<endl<<r2.h<<endl;
    cout<<p2->Area()<<endl;
    cout<<rr.w<<endl;
    CRectangle r3;
    r3.Init(3,4);
    PrintRectangle(r3);
    return 0;
}
