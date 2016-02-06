//
//  main.cpp
//  prepared_for_battle
//
//  Created by hankang yang on 2/5/16.
//  Copyright © 2016 hankang yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// warrior class

class warrior{
private:
    //string warrriorKind[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
    string Name;
    string base[2] = {"red","blue"};
    int No, Life, Attc;
public:
    warrior(string warriorName, int warriorLife = 1, int warriorNo = 1, int warriorAtt = 0);
    void Print();
};

// warrior constructor function
warrior::warrior(string warriorName, int warriorLife, int warriorNo, int warriorAtt){
    Name = warriorName;
    Life = warriorLife;
    Attc = warriorAtt;
    No   = warriorNo;
}
void warrior::Print(){
    cout<< Name << " "<<Life<<" "<<No<<endl;
}

// headquarter class
class Headquarters{
public:
    string name;
    int baselife;
    int warriorlifelim[5];
    string warrriorKind[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
    int warrriorOrder1[5] = { 2, 3, 4, 1, 0};
    int warrriorOrder2[5] = { 3, 0, 1, 2, 4};
    int warrriorOrder[5];
    int warrriorNo[5] = {0, 0, 0, 0, 0};
    warrior soldier;

    Headquarters(string base,int* wlife, int life,string warriorName = "dragon", int warriorLife = 3, int warriorNo = 1, int warriorAtt = 2);
    void Produce();
    void Print(int i);
    
};


// constructor function
Headquarters::Headquarters(string base,int* wlife, int life,string warriorName, int warriorLife, int warriorNo, int warriorAtt):soldier(warriorName,warriorLife,warriorNo,warriorAtt){
    name = base;
    baselife = life;
    for (int i = 0; i<5; i++) {
        warriorlifelim[i] = wlife[i];
    }
    
}

// produce function
void Headquarters::Produce(){
    int i = 0, count = 0;;
    int min = *min_element(warriorlifelim,warriorlifelim+7);
    if (name == "red") {
        for (int i = 0; i<5; i++) {
            warrriorOrder[i] = warrriorOrder1[i];
        }
    }
    else{
        for (int i = 0; i<5; i++) {
            warrriorOrder[i] = warrriorOrder2[i];
        }
    }
    
    while( baselife >=min){
        if(baselife -  warriorlifelim[warrriorOrder[i]]>= 0){
            baselife -= warriorlifelim[warrriorOrder[i]];
            
            count ++;
            warrriorNo[warrriorOrder[i]]++;
            cout<<name<<" "<<warrriorKind[warrriorOrder[i]]<<" "<<count<<" born"<<" with strength "<<warriorlifelim[warrriorOrder[i]]<<", "<<warrriorNo[warrriorOrder[i]]<<" "<<warrriorKind[warrriorOrder[i]]<<" in "<<name<<" headquarter"<<endl;
            i++;
            
            
        }
        else{
            i++ ;
        }
    }
    cout<<name<<" headquarter stops making warrioros"<<endl;
    
    
}
// print function
void Headquarters:: Print(int i){
    if (name == "red") {
        for (int i = 0; i<5; i++) {
            warrriorOrder[i] = warrriorOrder1[i];
        }
    }
    else{
        for (int i = 0; i<5; i++) {
            warrriorOrder[i] = warrriorOrder2[i];
        }
    }
    cout<<name<<" "<<warrriorOrder[i]<<" "<<warrriorKind[warrriorOrder[i]]<<" with strength "<<warriorlifelim[warrriorOrder[i]]<<" baselife "<<baselife<<endl;
}


int main(int argc, const char * argv[]) {
    int wlifelim[] = {3,4,5,6,7};
    int baselife = 20;
    warrior warriortest("dragon",2,1,2);
    Headquarters red("red",wlifelim,baselife), blue("blue",wlifelim,baselife);


    //blue.Print(1);
    //red.Print(2);
    //red.Produce();
    //blue.Produce();

    int min = *min_element(red.warriorlifelim,red.warriorlifelim+7);
    int i1 = 0, count1 = 0,i2 = 0, count2 = 0, printcout1 = 0,printcout2 = 0, timecount = 0;
    cout<<"Case 1:"<<endl;
    while( red.baselife >=min||blue.baselife>=min){
        if(red.baselife -  red.warriorlifelim[red.warrriorOrder1[i1]]>= 0){
            red.baselife -= red.warriorlifelim[red.warrriorOrder1[i1]];
            
            count1 ++;
            red.warrriorNo[red.warrriorOrder1[i1]]++;
            cout<<setfill('0')<<setw(3)<<timecount<<" "<<red.name<<" "<<red.warrriorKind[red.warrriorOrder1[i1]]<<" "<<count1<<" born"<<" with strength "<<red.warriorlifelim[red.warrriorOrder1[i1]]<<", "<<red.warrriorNo[red.warrriorOrder1[i1]]<<" "<<red.warrriorKind[red.warrriorOrder1[i1]]<<" in "<<red.name<<" headquarter"<<endl;
            i1++;
            
            
        }
        else{
            i1++ ;
        }
        
        if(blue.baselife -  blue.warriorlifelim[blue.warrriorOrder2[i2]]>= 0){
            blue.baselife -= blue.warriorlifelim[blue.warrriorOrder2[i2]];
            
            count2 ++;
            blue.warrriorNo[blue.warrriorOrder2[i2]]++;
            cout<<setfill('0')<<setw(3)<<timecount<<" "<<blue.name<<" "<<blue.warrriorKind[blue.warrriorOrder2[i2]]<<" "<<count2<<" born"<<" with strength "<<blue.warriorlifelim[blue.warrriorOrder2[i2]]<<", "<<blue.warrriorNo[blue.warrriorOrder2[i2]]<<" "<<blue.warrriorKind[blue.warrriorOrder2[i2]]<<" in "<<blue.name<<" headquarter"<<endl;
            i2++;
            
            
        }
        else{
            i2++ ;
        }
        
        if (red.baselife <min&&printcout1 == 0) {
            cout<<setfill('0')<<setw(3)<<timecount<<" "<<red.name<<" headquarter stops making warrioros"<<endl;
            printcout1 ++;
        }
        if (blue.baselife <min&&printcout2 == 0) {
            cout<<setfill('0')<<setw(3)<<timecount<<" "<<blue.name<<" headquarter stops making warrioros"<<endl;
            printcout2 ++;
        }
        timecount++;
    }
    
    
    return 0;
}
