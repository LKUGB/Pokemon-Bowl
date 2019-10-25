//
// Created by MSI on 2019/10/18.
//

#include "Pokemon.h"
#include <iostream>

using namespace std;


    //default constructor
    Pokemon::Pokemon() {
        this->Name = "";
        this->CombatPower = 0;
        this->Attack = 0;
        this->Defense = 0;
        this->SpAttack = 0;
        this->SpDefense = 0;
    }

    //alternative constructor
    Pokemon::Pokemon(string Name, int CombatPower, int Attack, int Defense, int SpAttack, int SpDefense) {
        this->Name = Name;
        this->CombatPower = CombatPower;
        this->Attack = Attack;
        this->Defense = Defense;
        this->SpAttack = SpAttack;
        this->SpDefense = SpDefense;
    }

    //declare a public member accessor function for each of the private members
    string Pokemon::getName() {
        return this->Name;
    }


    int Pokemon::getCombatPower() {
        return this->CombatPower;
    }

    int Pokemon::getAttack() {
        return this->Attack;
    }

    int Pokemon::getDefense() {
        return this->Defense;
    }

    int Pokemon::getSpAttack() {
        return this->SpAttack;
    }

    int Pokemon::getSpDefense() {
        return this->SpDefense;
    }
    int Pokemon::setCombatPower(int CP) {
    this->CombatPower = CP;
}




