#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Pokemon.h"
#include "PokeBowl.h"

using namespace std;

int strtoi(string s) {
    return atoi(s.c_str());
}

int main() {

    vector<int> pokeNumber;

    ifstream inFS;
    // open file
    inFS.open("../Pokemon.dat");
    // check whether open file is successful
    if (!inFS.is_open()) {
        cout << "Unable to open Pokemon.dat" << endl;
        return -1;
    }

    string line;

    // skips first row
    getline(inFS, line);
    // read in each line until end of file

    vector<Pokemon> pokeVector;
    while (getline(inFS, line)) {
        istringstream pokemon(line);
        string substring;

        // read in Pokemon number
        getline(pokemon, substring, ',');
        int num = strtoi(substring);

        // read in Pokemon name
        getline(pokemon, substring, ',');
        string name = substring;

        // ignore next few columns
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');

        // read in attack
        getline(pokemon, substring, ',');
        int attack = strtoi(substring);

        // read in defense
        getline(pokemon, substring, ',');
        int defense = strtoi(substring);

        // read in special attack
        getline(pokemon, substring, ',');
        int spAttack = strtoi(substring);

        // read in special defense
        getline(pokemon, substring, ',');
        int spDefense = strtoi(substring);

        // assign a random Combat Power
        int combatPower = rand() % 3991 + 10;

        bool isDuplicate = false;

        for( int i = 0; i < pokeNumber.size(); i++ ) {
            if( num == pokeNumber.at(i)) {
                isDuplicate = true;
            }
        }

        // At this point, read in a file with:
        // num (int), name (string), attack (int), defense (int), spAttack (int), spDefense (int)
        // Initialized combatPower (int) to a random value 10 to 4000

        // FINISH ME
        //storing the parameters into a object vector
        //define a pokemon object
        Pokemon randPokemon;
        randPokemon = Pokemon(name, combatPower, attack, defense, spAttack, spDefense); //call alternative constructor
        pokeVector.push_back(randPokemon); // add object to the end of the pokemon vector
    }

    // close file
    inFS.close();

    // FINISH ME
    //simulate a battle between pairs of Pokemon
    int k = 1, j = 0;
    int pokeWin; //used to determine the return value after the Bowl function
    for(int i = 1; i < pokeVector.size(); i++){
            pokeWin = PokeBowl::Bowl(pokeVector.at(j), pokeVector.at(k), false);
            //whoever win will be preserved and change the index of the lose pokemon to the next pokemon i; i will increment at the end of the for loop, so it would not let a pokemon attack itself
                if(pokeWin == 1) { //second pokemon win
                    j = i; //change the index of the second pokemon to the next pokemon
                }
                else { // first pokemon win
                    k = i; //change the index of the first pokemon to the next pokemon
                }
    }

    //claim who finally win the bowl
    if(pokeWin == 1){
        cout << pokeVector.at(k).getName() << "won!"; //the last round of game: the second pokemon won
    }
    else{
        cout << pokeVector.at(j).getName() << "won!"; //the last round of game: the first pokemon won
    }
}
