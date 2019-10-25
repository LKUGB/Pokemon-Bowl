//
// Created by MSI on 2019/10/18.
//

#ifndef PROJECT_5_PART_1_LKUGB_POKEBOWL_H
#define PROJECT_5_PART_1_LKUGB_POKEBOWL_H
#include <string>
#include <ctime>

#endif //PROJECT_5_PART_1_LKUGB_POKEBOWL_H

using namespace std;




class Pokemon{
private: //declare private members
        string Name;
        int CombatPower;
        int Attack;
        int Defense;
        int SpAttack;
        int SpDefense;


public:
        Pokemon(); //default constructor
        Pokemon(string, int, int, int, int, int); //alternative constructor;
        //declare a public member accessor function for each of the private members
        string getName();
        int getCombatPower();
        int getAttack();
        int getDefense();
        int getSpAttack();
        int getSpDefense();
        int setCombatPower(int);
};