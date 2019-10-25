//
// Created by MSI on 2019/10/24.
//

#include "PokeBowl.h"
#include <iostream>

//declare a member function named Bowl and will determine which pokemon wins
int PokeBowl::Bowl(Pokemon pokemon1, Pokemon pokemon2, bool verbose) {
    if (verbose) {
        cout << "Let the PokeBowl Begin..." << endl;
    }
    srand(time(0));
    //define a variable to specify who is active in the current round
    //determine who will attack first by initializing this variable with random number [0,1]
    int activePlayer = rand() % 2;
    //end the battle when the CP of either pokemon is depleted
    while (pokemon1.getCombatPower() >= 0 && pokemon2.getCombatPower() >= 0) {
        if (activePlayer == 0) {
            //pokemon 1 goes first
            //determine whether the pokemon will use regular attack or special attack
            if (rand() % 2 == 0) {
                //the pokemon uses regular attack
                if (rand() % 2 == 0) {
                    //the other pokemon uses regular defense
                    //regular attack and regular defense
                    //modify the CP of the pokemon being attacked
                    pokemon2.setCombatPower(pokemon2.getCombatPower() - (pokemon1.getAttack() - 0.10 * pokemon2.getDefense()));
                    if (verbose) {
                        cout << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") attacks, "
                             << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") defends..." << endl;
                    }
                } else {
                    //the other pokemon uses special defense (1/10 of the damage value taken)
                    //regular attack and special defense
                    //modify the CP of the pokemon being attacked
                    pokemon2.setCombatPower(pokemon2.getCombatPower() - (pokemon1.getAttack() - 0.10 * pokemon2.getSpDefense()));
                    if (verbose) {
                        cout << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") attacks, "
                             << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") special defends..." << endl;
                    }
                }
            } else {
                //pokemon uses special attack
                if (rand() % 2 == 0) {
                    //the other pokemon uses regular defense
                    //SpAttack and regular defense
                    //modify the CP of the pokemon being attacked
                    pokemon2.setCombatPower(pokemon2.getCombatPower() - (pokemon1.getSpAttack() - 0.10 * pokemon2.getDefense()));
                    if (verbose) {
                        cout << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") special attacks, "
                             << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") defends..." << endl;
                    }
                } else {
                    //the other pokemon uses special defense (1/10 of the damage value taken)
                    //special attack and special defense
                    //modify the CP of the pokemon being attacked
                    pokemon2.setCombatPower(pokemon2.getCombatPower() - (pokemon1.getSpAttack() - 0.10 * pokemon2.getSpDefense()));
                    if (verbose) {
                        cout << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") special attacks, "
                             << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") special defends..." << endl;
                    }
                }
            }
            //switch players (pokemon 2 is active)
            activePlayer = 1;
        }

            //when pokemon 2 goes first
        else {
            //pokemon 2 goes first
            //determine whether the pokemon will use regular attack or special attack
            if (rand() % 2 == 0) {
                //pokemon uses regular attack
                if (rand() % 2 == 0) {
                    //the other pokemon uses regular defense
                    //regular attack and regular defense
                    //modify the CP of the pokemon being attacked
                    pokemon1.setCombatPower(pokemon1.getCombatPower() - (pokemon2.getAttack() - 0.10 * pokemon1.getDefense()));
                    if (verbose) {
                        cout << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") attacks, "
                             << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") defends..." << endl;
                    }
                } else {
                    //the other pokemon uses special defense (1/10 of the damage value taken)
                    //regular attack and special defense
                    //modify the CP of the pokemon being attacked
                    pokemon1.setCombatPower(pokemon1.getCombatPower() - (pokemon2.getAttack() - 0.10 * pokemon1.getSpDefense()));
                    if (verbose) {
                        cout << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") attacks, "
                             << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") special defends..."
                             << endl;
                    }
                }
            } else {
                //pokemon uses special attack
                if (rand() % 2 == 0) {
                    //the other pokemon uses regular defense
                    //special attack and regular defense
                    //modify the CP of the pokemon being attacked
                    pokemon1.setCombatPower(pokemon1.getCombatPower() - (pokemon2.getSpAttack() - 0.10 * pokemon1.getDefense()));
                    if (verbose) {
                        cout << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") special attacks, "
                             << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") defends..." << endl;
                    }
                } else {
                    //the other pokemon uses special defense (1/10 of the damage value taken)
                    //special attack and special defense
                    //modify the CP of the pokemon being attacked
                    pokemon1.setCombatPower(pokemon1.getCombatPower() - (pokemon2.getSpAttack() - 0.10 * pokemon1.getSpDefense()));
                    if (verbose) {
                        cout << pokemon2.getName() << " (" << pokemon2.getCombatPower() << ") special attacks, "
                             << pokemon1.getName() << " (" << pokemon1.getCombatPower() << ") special defends..."
                             << endl;
                    }
                }
            }
            //switch players (pokemon1 is active)
            activePlayer = 0;
        }
    }

    //determine which pokemon wins or whether it is a draw
    if (pokemon1.getCombatPower() <= 0 && pokemon2.getCombatPower() <= 0) {
        cout << "It is a draw" << endl;
        return 0; //it's a draw
    } else if (pokemon2.getCombatPower() <= 0) {
        cout << pokemon1.getName() << " wins!!" << endl;
        return -1; //pokemon 1 wins

    } else {
        cout << pokemon2.getName() << " wins!!" << endl;
        return 1; //pokemon 2 wins
    }
}
